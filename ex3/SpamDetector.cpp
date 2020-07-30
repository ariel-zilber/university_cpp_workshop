#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "HashMap.hpp"
#include <boost/tokenizer.hpp>
#include <iostream>

/**
* @def EXPECTED_PARAM_COUNT 4
* @brief The expected count of parameters
*/
#define  EXPECTED_PARAM_COUNT 4


/**
* @def DATABASE_COL_NUM 2
* @brief
*/
#define  DATABASE_COL_NUM 2

/**
* @def DB_PATH_ARG 1
* @brief The path of the db
*/
#define  DB_PATH_ARG 1


/**
* @def MAIL_PATH_ARG 2
* @brief The path of the mail
*/
#define  MAIL_PATH_ARG 2


/**
* @def THRESHOLD_ARG 3
* @brief The spam threshold
*/
#define  THRESHOLD_ARG 3

/**
* @def USAGE_MSG "Usage: SpamDetector <database path> <message path> <threshold>"
* @brief Message representing invalid usage
*/
#define  USAGE_MSG "Usage: SpamDetector <database path> <message path> <threshold>"

/**
* @def INVALID_INPUT_MSG "Invalid input"
* @brief Representing when invaid input was given
*/
#define  INVALID_INPUT_MSG "Invalid input"

/**
* @def SPAM_MESSAGE    "SPAM"
* @brief  Representing when the input is spam
*/
#define SPAM_MESSAGE    "SPAM"

/**
* @def NOT_SPAM_MESSAGE  "NOT_SPAM"
* @brief representing when the input is not spam
*/
#define NOT_SPAM_MESSAGE  "NOT_SPAM"

/**
 *  Counts occurrences of substring in string
 * @param str
 * @param sub
 * @return
 */
int _countOccurrences(const std::string &str,   std::string  sub)
{
    if (sub.length() == 0)
    {
        return 0;
    }

    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
         offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

/***
 * Checks whenever a given string represents a nubmer
 * @param str
 * @return
 */
static bool _isNumber(const std::string &str)
{
    for (char i : str)
    {
        if (isdigit(i) == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * Validates the valus given as input args
 * @param firstFilePath The first given parameter
 * @param secondFilePath The second given parameter
 * @param thresholdStr  The third given parameter
 * @return whenver the arguments are valid or not
 */
bool _validateInputArgs(std::string firstFilePath, std::string secondFilePath, const std::string &thresholdStr)
{

    // Check  that the path are of existing files
    if ((!boost::filesystem::exists(firstFilePath)) | (!boost::filesystem::exists(secondFilePath)))
    {
        return false;
    }

    // Check that the third number is a Natrual number
    if (!_isNumber(thresholdStr))
    {
        return false;

    }

    // convert the string to integer
    int threshold = std::stoi(thresholdStr);

    // Make sure that the threshold is positive
    if (threshold <= 0)
    {
        return false;
    }


    return true;
}

/**
 * Read a
 * @param fileName
 * @return
 */
std::vector<std::vector<std::string>> _readDBFile(const std::string &fileName)
{

    std::ifstream file(fileName);
    boost::char_separator<char> sep{",", "", boost::keep_empty_tokens};

    std::vector<std::vector<std::string>> dbInputByRow;

    std::string line;

    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::tokenizer<boost::char_separator<char>> tok{line, sep};
        for (const auto &t:tok)
        {
            vec.push_back(t);
        }

        dbInputByRow.push_back(vec);
    }

    file.close();

    return dbInputByRow;
}

/**
 * Read a file  content intro a string
 * @param fileName  the name of the file
 * @return  the content
 */
std::string _parseFileToStringBuffer(const std::string &fileName)
{
    std::ifstream in(fileName);
    if (!in)
    {
        return "";
    }

    in.seekg(0, std::ios::end);
    size_t len = in.tellg();
    in.seekg(0);
    std::string contents(len + 1, '\0');
    in.read(&contents[0], len);
    return contents;

}

/**
 * validation  That the provided input database file  is a valid
 * @param dbInputByRow
 * @return

 */
static bool _isInputDBValid(std::vector<std::vector<std::string> > &dbInputByRow)
{

    for (auto ptr = dbInputByRow.begin(); ptr < dbInputByRow.end(); ptr++)
    {
        // check num of cols parameter
        if (ptr->size() != DATABASE_COL_NUM)
        {
            return false;
        }

        // Check that the are not empty
        if (ptr->at(0).empty() || ptr->at(1).empty())
        {
            return false;
        }

        // Make sure that the second column contains a number
        if (!_isNumber(ptr->at(1)))
        {
            return false;
        }

    }

    return true;

}

/**
 * Initalize a db 
 * @param dbInputByRow 
 * @return 
 */
HashMap<std::string, int> _initializeDataBase(std::vector<std::vector<std::string> > dbInputByRow)
{
    std::vector<std::string> keys;
    std::vector<int> values;

    for (auto &row : dbInputByRow)
    {
        std::string key = row.at(0);
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        int value = std::stoi(row.at(1));
        keys.push_back(key);
        values.push_back(value);
    }


    return HashMap<std::string, int>(keys, values);
}

/**
 * Parses a mail file and get the score indicating it is a spam
 * @param dataBase
 * @param mailFilePath
 * @return
 */
int _getMailSpamScore(HashMap<std::string, int> &dataBase, const std::string &mailFilePath)
{
    std::string mailDataList = _parseFileToStringBuffer(mailFilePath);
    transform(mailDataList.begin(), mailDataList.end(), mailDataList.begin(), ::tolower);

    int totalScore = 0;
    for (auto query = dataBase.begin(); query != dataBase.end(); query++)
    {
      totalScore = totalScore + _countOccurrences(mailDataList, query->first) * query->second;
    }

    return totalScore;
}

/**
* @brief
 *
 * The main for exercise 3
 * The program operates in the following manner:
 * 1. Reads and process a csv file representing a database
 * 2. Reads a Mail message
 * 3. Print whenver the given mail is spam or not
 *
* @param argc
* @param argv  Should be in the follwong format :<database path> <message path> <threshold>
* */
int main(int argc, char **argv)
{

    // Check the number of given parameters
    if (argc != EXPECTED_PARAM_COUNT)
    {
        std::cerr << USAGE_MSG << std::endl;
        exit(EXIT_FAILURE);
    }

    // Check the validity of the input
    if (!_validateInputArgs(argv[DB_PATH_ARG], argv[MAIL_PATH_ARG], argv[THRESHOLD_ARG]))
    {
        std::cerr << INVALID_INPUT_MSG << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read a db file row by row
    std::vector<std::vector<std::string> > dbInputByRow = _readDBFile(argv[DB_PATH_ARG]);

    if (!_isInputDBValid(dbInputByRow))
    {
        std::cerr << INVALID_INPUT_MSG << std::endl;
        exit(EXIT_FAILURE);
    }

    // parse the threshold string
    int threshold = std::stoi(argv[THRESHOLD_ARG]);

    // Initialize the database
    HashMap<std::string, int> dataBase = _initializeDataBase(dbInputByRow);

    // Parse a mail file and get it's score
    if (_getMailSpamScore(dataBase, argv[MAIL_PATH_ARG]) >= threshold)
    {
        std::cout << SPAM_MESSAGE << std::endl;
    }
    else
    {
        std::cout << NOT_SPAM_MESSAGE << std::endl;
    }

    return 0;

}