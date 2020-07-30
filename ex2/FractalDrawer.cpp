#include "boost/filesystem.hpp"
#include <boost/tokenizer.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Fractal.h"

/**
* @def FRACTAL_DRAWER_BAD_USAGE "Usage: FractalDrawer <file path>"
* @brief Message appearing when invalid parameters number were given to the program
*/
#define FRACTAL_DRAWER_BAD_USAGE "Usage: FractalDrawer <file path>"

/**
* @def FRACTAL_DRAWER_BAD_INPUT "Invalid input"
* @brief message displayed when an invalid input was given
*/
#define FRACTAL_DRAWER_BAD_INPUT "Invalid input"


/**
* @def EXPECTED_PARAM_COUNT 2
* @brief The expected number of apgument that should be given to the program
*/
#define EXPECTED_PARAM_COUNT 2

/**
* @def CSV_COL_FRACTAL_TYPE 0
 * @brief The col represnting the column type in the csv
*/
#define CSV_COL_FRACTAL_TYPE 0

/**
* @def CSV_COL_FRACTAL_DIM 1
 * @brief The col represnting the column dimention in the csv
*/
#define CSV_COL_FRACTAL_DIM 1

/**
* @def MIN_FRACTAL_DIM_LEN 1
 * @brief The minimal dimention size a fractal might  have
*/
#define  MIN_FRACTAL_DIM_LEN 1

/**
* @def MAX_FRACTAL_DIM_LEN 6
 * @brief The maximal dimention size a fractal might  have
*/
#define  MAX_FRACTAL_DIM_LEN 6

/**
* A utility class that reads a csv file line by line
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class CSVReader
{
    std::string fileName;

public:

    // constructors:

    /**
     *
     * @param filename
     */
    CSVReader(std::string filename) :
            fileName(filename)
    {}

    // methods:

    /**
     * Setter for the fil name
     * @param newFileName
     */
    void setFileName(std::string newFileName)
    {
        fileName = newFileName;
    }

    /**
     * Getter for the file name
     * */
    std::string getFileName()
    {
        return fileName;
    }

    /**
     * Opens a given csv file path and retrive it's data
     * */
    std::vector<std::vector<std::string> > getData()
    {

        std::ifstream file(fileName);
        boost::char_separator<char> sep{","};

        std::vector<std::vector<std::string> > dataList;

        std::string line;

        while (getline(file, line))
        {
            std::vector<std::string> vec;
            boost::tokenizer<boost::char_separator<char>> tok{line, sep};
            for (const auto &t:tok)
            {
                vec.push_back(t);
            }

            dataList.push_back(vec);
        }

        file.close();

        return dataList;
    }
};

/**
* A utility class that prints a fractal in ascii format
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
class FractalDrawer
{
public:

    // Constructors:
    /**
     * Creates a new fractal drawer where it's fractal list is given from a csv file
     * @param filePath  the path of the csv
     */
    explicit FractalDrawer(std::string filePath)
    {

        if (!boost::filesystem::exists(filePath))
        {
            std::cerr << FRACTAL_DRAWER_BAD_INPUT << std::endl;
            exit(EXIT_FAILURE);
        }

        CSVReader reader(filePath);
        std::vector<std::vector<std::string> > dataList = reader.getData();


        if (!_isInputValid(dataList))
        {
            std::cerr << FRACTAL_DRAWER_BAD_INPUT << std::endl;
            exit(EXIT_FAILURE);
        }

        _createFractals(dataList);

    }

    // methods:

    /**
     * Destructor for the FractalDrawer
     */
    ~FractalDrawer()
    {
        for (auto &i : fractalsList)
        {
            delete i;
        }
        fractalsList.clear();
    }

    /**
     * Draws the list of given fractals in the opposite order which they were given
     *
     * */
    void drawFractalsAscii()
    {

        for (auto fractal : fractalsList)
        {
            _drawFractalAscii(fractal);
        }
    }


private:

    // methods:

    /**
     * Creates fractal object from a provided vector list of cells in a csv file
     * @param dataList
     */
    void _createFractals(const std::vector<std::vector<std::string> > &dataList)
    {
        int fractalType;
        int dim;

        for (auto ptr = dataList.rbegin(); ptr != dataList.rend(); ++ptr)
        {
            fractalType = std::stoi(ptr->at(CSV_COL_FRACTAL_TYPE));
            dim = std::stoi(ptr->at(CSV_COL_FRACTAL_DIM));

            Fractal *newFractal = FractalFactory::createFractal(fractalType, dim);
            fractalsList.push_back(newFractal);
        }

    }

    /**
     * validation checks on an input file
     * @param dataList
     * @return
     */
    static bool _isInputValid(std::vector<std::vector<std::string> > dataList)
    {

        boost::char_separator<char> sep{","};

        int fractal;
        int dim;

        for (auto ptr = dataList.begin(); ptr < dataList.end(); ptr++)
        {

            // check num of cols parameter
            if (ptr->size() != EXPECTED_PARAM_COUNT)
            {
                return false;
            }

            // make sure the parameters in the column represent valid numbers
            if (!_isNumber(ptr->at(CSV_COL_FRACTAL_TYPE)) || !_isNumber(ptr->at(CSV_COL_FRACTAL_DIM)))
            {
                return false;
            }

            // get the fractal and dimentiuon of the csv row
            fractal = std::stoi(ptr->at(CSV_COL_FRACTAL_TYPE));
            dim = std::stoi(ptr->at(CSV_COL_FRACTAL_DIM));

            // make sure that a valid fractal type was given
            if (fractal > 3 || fractal < 1)
            {
                return false;
            }

            // make sure that the dimention are in the valid range
            if (dim < MIN_FRACTAL_DIM_LEN || dim > MAX_FRACTAL_DIM_LEN)
            {
                return false;
            }

        }

        return true;

    }

    /**
     * Displays the structure of a fractal as ascii on the terminal
     * @param fractal
     */
    static void _drawFractalAscii(Fractal *fractal)
    {

        std::vector<bool> fractalMatrix = fractal->getFractalMatrix();

        int cellCount = 0;
        int rowLen = int(sqrt(fractalMatrix.size()));

        for (auto it = fractalMatrix.begin(); it < fractalMatrix.end(); it++)
        {

            if (*it)
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }

            cellCount++;

            if (cellCount % rowLen == 0)
            {
                std::cout << std::endl;

            }
        }

        std::cout << std::endl;

    };

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

    // data members:
    std::vector<Fractal *> fractalsList;

};

/**
* @brief
 *
 * The main for exercise 2
 * The program operates in the following manner:
 * 1. Reads and process a csv file representing a list of Fractals
 * 2. Prints the Fractals as ascii to the terminal
 *
* @param argc
* @param argv
* */
int main(int argc, char **argv)
{

    // checks that only a single parameter was given
    if (argc != EXPECTED_PARAM_COUNT)
    {
        std::cerr << FRACTAL_DRAWER_BAD_USAGE << std::endl;
        exit(EXIT_FAILURE);
    }

    // draw the fractal shapes:
    FractalDrawer drawer(argv[CSV_COL_FRACTAL_DIM]);
    drawer.drawFractalsAscii();

    return 0;

}