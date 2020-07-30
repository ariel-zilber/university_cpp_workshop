#ifndef EX3_CPP_HASHMAP_HPP
#define EX3_CPP_HASHMAP_HPP

#include <utility>
#include <iterator>
#include <vector>
#include <map>
#include <iostream>

/**
* @def DEFAULT_INITIAL_HASH_CAPACITY 16
* @brief  The  default inital size of a hash map
*/
#define  DEFAULT_INITIAL_HASH_CAPACITY 16


/**
 * @def DEFAULT_MIN_LOAD_FACTOR 0.25
* @brief  The  default inital size of a hash map
 * */
#define  DEFAULT_MIN_LOAD_FACTOR 0.25

/**
 * @def DEFAULT_MIN_LOAD_FACTOR 0.25
* @brief  The  default inital size of a hash map
 * */
#define  DEFAULT_MAX_LOAD_FACTOR 0.75


/**
* @def NOT_FOUND_BUCKET 0
* @brief  defined non found value
*/
#define NOT_FOUND_BUCKET 0

/**
* @def NOT_FOUND_BUCKET 0
* @brief  defined non found value
*/
#define  BUCKET_NOT_FOUND_EXCEPTION 0


/**
* @def LOAD_FACTOR_LIMIT_EXCEPTION -1
* @brief  Load factor exception
*/

#define  LOAD_FACTOR_LIMIT_EXCEPTION -1

#define  BUCKET_INDEX_NOT_FOUND_EXCEPTION -1

#define  KEYS_VALUES_SIZES_EXCEPTION -1

/**
* @def NOT_FOUND_BUCKET_INDEX  0
* @brief  defined non found value
*/
#define  MIN_LOAD_FACTOR_LIMIT 0

/**
* @def MAX_LOAD_FACTOR_LIMIT 1
* @brief The maximal value for the load factor
*/
#define  MAX_LOAD_FACTOR_LIMIT 1

/**
* A general representation of hash map
*
* @author - Ariel Zilbershtein
* @CS login - arikzil
*
* */
template<class KeyT, class ValueT>
class HashMap
{

public:

    // constructors

    /**
     * Initialize an empty hash map
    */
    HashMap();

    /**
     * Initialize an empty hash map with explicit bounds to the load factor
     * @param lowerLoadFactor  The lower bound
     * @param higherLoadFactor  The upper bound
     */
    HashMap(double lowerLoadFactor, double higherLoadFactor);


    /**
     * @brief Copy constructor of an other hash map
    */
    HashMap(HashMap const &other);

    /**
     * @brief constructor that recives 2 vectors
     * and keeps the values in the hash map in the given order
     * @param keys list of keys
     * @param values list of values
     *
     * **/
    HashMap(std::vector<KeyT> keys, std::vector<ValueT> values);

    /**
     * Destructor
     * **/
    ~HashMap();
    // methods:

    /**
     *
     * @brief Returns the total number of items in the hash map
     * @return hash map items count
     * */
    int size();

    /**
      *
      * @brief Returns the total number of items in the hash map
      * @return hash map items count
      * */
    int size() const;

    /**
     * @brief Return the current capacity of the hash map
     * @return  the capacity of the hash map
     * **/
    int capacity();

    /**
     * @brief Return the current capacity of the hash map
     * @return  the capacity of the hash map
     * **/

    int capacity() const;

    /**
     * @brief checks whenever the hash map is empty or not
     * @return whenever the hash map is empty
     * */
    bool empty();

    /**
     * @brief checks whenever the hash map is empty or not
     * @return whenever the hash map is empty
     * */
    bool empty() const;

    /**
     * @brief adds an item to the hash map
     * @param key
     * @param value
     * @return bool value representing whenever the item was inserted successfully.
     *
     * */
    bool insert(const KeyT &key, const ValueT &value);


    /**
     * @brief checks the
     * @param key the key to check
     * @return whenever the key is in the the hash map
     */
    bool containsKey(const KeyT &key);

    /**
       * @brief checks the
       * @param key the key to check
       * @return whenever the key is in the the hash map
       */
    bool containsKey(const KeyT &key) const;

    /**
     * @brief takes a key as  a parameter and returns the assocciated values.
     * @param key  the input key
     * @return ValueT   the value to return
     *
     * */
    ValueT &at(const KeyT &key);


    /**
     * @brief takes a key as  a parameter and returns the assocciated values.
     * @param key  the input key
     * @return ValueT   the value to return
     *
     * */
    const ValueT &at(const KeyT &key) const;

    /**
     *@brief  deletes an item in the hash map
     * @param Key
     * @return bool representation whenever the item was deleted successfully or not
     * */
    bool erase(const KeyT &key);

    /**
     * @brief returns the load factor
     * @param the load factor of the hash map
     * **/
    double getLoadFactor();


    /**
     *
     *@brief takes as a parameter a key and return the size of the bucket
     * @param key the input key
     * @return returns an int .When a the value of the bucket does not appear
     * then it returns the size of the bucket
     *
     * */
    int bucketSize(const KeyT &key);

    /**
     *
     *@brief takes as a parameter a key and return the size of the bucket
     * @param key the input key
     * @return returns an int .When a the value of the bucket does not appear
     * then it returns the size of the bucket
     *
     * */
    int bucketSize(const KeyT &key) const;

    /**
     *@brief takes a key as input and returns the basket index.
     * @param key  the input key
     * @return the bucket index
     * */
    int bucketIndex(const KeyT &key);

    /**
     *@brief takes a key as input and returns the basket index.
     * @param key  the input key
     * @return the bucket index
     * */
    int bucketIndex(const KeyT &key) const;

    /**
     * @brief deletes all the items in the hash map
     * */
    void clear();


    /**
     * @brief copy-constructor assigment
     * @param otherMap
     * @return the result of the assigment
     * **/
    HashMap<KeyT, ValueT> &operator=(HashMap<KeyT, ValueT> const &otherMap);

    /**
    * @brief checks whenever two sets contain the same value
     * @param otherMap
     * @return whenever the values are the same
    * **/
    bool operator==(HashMap<KeyT, ValueT> const &otherMap);

    bool operator==(const HashMap<KeyT, ValueT> &otherMap) const;


    /**
     * @brief checks whenever the wo sets contain the same values
     * @param otherMap
     * @return whenever the values are not the same
     * */
    bool operator!=(HashMap<KeyT, ValueT> const &otherMap);

    bool operator!=(HashMap<KeyT, ValueT> const &otherMap) const;

    /**
     * Subscript overload
     * @param otherMap
     * @return
     */
    ValueT &operator[](KeyT const &otherMap);


    /**
     * Subscript overload
     * @param otherMap
     * @return
     */
    ValueT &operator[](KeyT const &otherMap) const;

    // iterators class

    /**
     * Const forward iterator on the hash map
    * @tparam KeyT
    * @tparam ValueT
    */
    class iterator;

    /**
     * end method for the const foward iterator
     *
     * */
    iterator end()
    {
        iterator it = iterator(this);
        return it.end();
    }

    /**
     * end method for the const foward iterator
     *
     * */
    iterator begin()
    {
        iterator it = iterator(this);
        return it.begin();
    }


    /**
     * end method for the const foward iterator
     *
     * */
    iterator end() const
    {
        iterator it = iterator(this);
        return it.end();
    }

    /**
     * end method for the const foward iterator
     *
     * */
    iterator begin() const
    {
        iterator it = iterator(this);
        return it.begin();
    }


    /**
     * end method for the const foward iterator
     *
     * */
    iterator cend() const
    {
        iterator it = iterator(this);
        return it.end();
    }

    /**
     * end method for the const foward iterator
     *
     * */
    iterator cbegin() const
    {
        iterator it = iterator(this);
        return it.begin();
    }


private:


    typedef std::vector<std::pair<KeyT, ValueT>> BucketCell;

    std::hash<KeyT> hashFunc;

    int totalSize;
    int totalCapacity;
    double lowerLoadFactor;
    double upperLoadFactor;
    BucketCell *buckets;

    /***
     * Hash function on a key
     * @param m_key
     * @return
     */
    int _hash(KeyT m_key);

    /***
      * Hash function on a key
      * @param m_key
      * @return
      */
    int _hash(KeyT m_key) const;

    /***
     * Increases or decrease  the size of the bucket array
     * @param larger
     */
    void _resize(bool larger);

    /***
     * Deletes a pair in a specific bucket
     * @param key
     * @param index
     */
    void _deleteKeyValuePair(KeyT key, int index);

    /**
     * Checks whenever a given bucket contains a key
     * @param cell
     * @param key
     * @return
     */
    bool _bucketContainsKey(BucketCell cell, const KeyT &key);

    /**
    * Checks whenever a given bucket contains a key
    * @param cell
    * @param key
    * @return
    */
    bool _bucketContainsKey(BucketCell cell, const KeyT &key) const;

    /**
     *  Returns a pair from a given bucket
     * @param cell
     * @param key
     * @return
     */
    std::pair<KeyT, ValueT> &_getBucketPair(BucketCell &cell, KeyT key);

    /**
    * Returns a pair from a given bucket
    * @param cell
    * @param key
    * @return
     */
    std::pair<KeyT, ValueT> &_getBucketPair(BucketCell &cell, KeyT key) const;

};
//=========================  Implementation  ================================//

/**
 * Initialize an empty hash map
*/
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT>::HashMap():HashMap(DEFAULT_MIN_LOAD_FACTOR, DEFAULT_MAX_LOAD_FACTOR)
{

}

/**
     * Initialize an empty hash map with explicit bounds to the load factor
     * @param lowerLoadFactor  The lower bound
     * @param higherLoadFactor  The upper bound
     */
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT>::HashMap(double lowerLoadFactor, double higherLoadFactor):
        lowerLoadFactor(lowerLoadFactor),
        upperLoadFactor(higherLoadFactor)
{

    // checks the load factor value ranges:
    if (lowerLoadFactor >= higherLoadFactor)
    {
        throw LOAD_FACTOR_LIMIT_EXCEPTION;
    }

    if (upperLoadFactor > MAX_LOAD_FACTOR_LIMIT || upperLoadFactor <= MIN_LOAD_FACTOR_LIMIT)
    {
        throw LOAD_FACTOR_LIMIT_EXCEPTION;
    }

    if (lowerLoadFactor > MAX_LOAD_FACTOR_LIMIT || lowerLoadFactor <= MIN_LOAD_FACTOR_LIMIT)
    {
        throw LOAD_FACTOR_LIMIT_EXCEPTION;
    }


    // Initialize the data members
    totalSize = 0;
    totalCapacity = DEFAULT_INITIAL_HASH_CAPACITY;
    buckets = new BucketCell[DEFAULT_INITIAL_HASH_CAPACITY];
}

/**
 * @brief Copy constructor of an other hash map
*/
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT>::HashMap(HashMap const &other):lowerLoadFactor(other.lowerLoadFactor),
                                                     upperLoadFactor(other.upperLoadFactor)
{
    // initialize the sizes
    totalCapacity = other.totalCapacity;
    totalSize = other.totalSize;

    // Initalize an array with empty values
    buckets = new BucketCell[totalCapacity];


    // copies the content of the other bucket
    for (int i = 0; i < totalCapacity; i++)
    {
        buckets[i] = BucketCell(other.buckets[i]);
    }
}

/**
 * @brief constructor that recieves 2 vectors
 * and keeps the values in the hash map in the given order
 * @param keys list of keys
 * @param values list of values
 *
 * **/
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT>::HashMap(std::vector<KeyT> keys, std::vector<ValueT> values):HashMap()
{
    int numOfKeys = keys.size();
    int numOfValues = values.size();

    if (numOfKeys != numOfValues)
    {
        throw KEYS_VALUES_SIZES_EXCEPTION;
    }

    for (int i = 0; i < numOfKeys; i++)
    {
        if (containsKey(keys[i]))
        {
            operator[](keys[i]) = values[i];
        }
        else
        {
            insert(keys[i], values[i]);
        }
    }
}

/**
 *
 * @brief Returns the total number of items in the hash map
 * @return hash map items count
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::size()
{
    return totalSize;
}


/**
 *
 * @brief Returns the total number of items in the hash map
 * @return hash map items count
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::size() const
{
    return totalSize;
}

/**
 * @brief Return the current capacity of the hash map
 * @return  the capacity of the hash map
 * **/
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::capacity()
{
    return totalCapacity;
}


/**
 * @brief Return the current capacity of the hash map
 * @return  the capacity of the hash map
 * **/
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::capacity() const
{
    return totalCapacity;
}

/**
 * @brief checks whenever the hash map is empty or not
 * @return whenever the hash map is empty
 * */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::empty()
{
    return totalSize == 0;
}

/**
 * @brief checks whenever the hash map is empty or not
 * @return whenever the hash map is empty
 * */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::empty() const
{
    return totalSize == 0;
}

/**
 * @brief adds an item to the hash map
 * @param key
 * @param value
 * @return bool value representing whenever the item was inserted successfully.
 *
 * */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::insert(const KeyT &key, const ValueT &value)
{
    // duplicate check
    if (containsKey(key))
    {
        return false;
    }

    // find the appropriate index
    int index = _hash(key);

    // get the load factor
    double loadFactor = getLoadFactor();

    // check for _resize
    if (loadFactor >= upperLoadFactor)
    {
        _resize(true);
        index = _hash(key);
    }

    // Create a   pair
    std::pair<KeyT, ValueT> newItem(key, value);

    // add the  pair
    buckets[index].push_back(newItem);
    totalSize++;

    return true;

}


/**
 * @brief checks the
 * @param key the key to check
 * @return whenever the key is in the the hash map
 */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::containsKey(const KeyT &key)
{
    // creates the appropriate hash index
    int bucketIndex = _hash(key);

    // makes sure that the bucket is in the limit of the buckets
    if (bucketIndex < 0 || bucketIndex >= totalCapacity)
    {
        return false;
    }

    return (_bucketContainsKey(buckets[bucketIndex], key));
}


/**
 * @brief checks the
 * @param key the key to check
 * @return whenever the key is in the the hash map
 */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::containsKey(const KeyT &key) const
{
    // creates the appropriate hash index
    int bucketIndex = _hash(key);

    // makes sure that the bucket is in the limit of the buckets
    if (bucketIndex < 0 || bucketIndex >= totalCapacity)
    {
        return false;
    }

    return (_bucketContainsKey(buckets[bucketIndex], key));
}

/**
 * @brief takes a key as  a parameter and returns the assocciated values.
 * @param key  the input key
 * @return ValueT   the value to return
 *
 * */
template<class KeyT, class ValueT>
ValueT &HashMap<KeyT, ValueT>::at(const KeyT &key)
{

    int index = bucketIndex(key);

    // checks whenever the bucket was found
    if (!_bucketContainsKey(buckets[index], key))
    {
        throw BUCKET_NOT_FOUND_EXCEPTION;
    }

    // return the appropriate location
    return _getBucketPair(buckets[index], key).second;
}


/**
 * @brief takes a key as  a parameter and returns the assocciated values.
 * @param key  the input key
 * @return ValueT   the value to return
 *
 * */
template<class KeyT, class ValueT>
const ValueT &HashMap<KeyT, ValueT>::at(const KeyT &key) const
{
    int index = bucketIndex(key);

    // checks whenever the bucket was found
    if (!_bucketContainsKey(buckets[index], key))
    {
        throw BUCKET_NOT_FOUND_EXCEPTION;
    }

    // return the appropriate location
    return _getBucketPair(buckets[index], key).second;
}


/**
 *@brief  deletes an item in the hash map
 * @param Key
 * @return bool representation whenever the item was deleted successfully or not
 * */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::erase(const KeyT &key)
{
    try
    {
        int index = bucketIndex(key);
        double loadFactor = getLoadFactor();
        totalSize = totalSize - 1;

        _deleteKeyValuePair(key, index);

        if (loadFactor <= lowerLoadFactor)
        {
            _resize(false);
        }

        return true;
    } catch (int e)
    {
        return false;
    }
}

/**
 * @brief returns the load factor
 * @param the load factor of the hash map
 * **/
template<class KeyT, class ValueT>
double HashMap<KeyT, ValueT>::getLoadFactor()
{
    // per the formula given in the description of the excersize
    return (double) (size()) / capacity();
}

/**
 *
 *@brief takes as a parameter a key and return the size of the bucket
 * @param key the input key
 * @return returns an int .When a the value of the bucket does not appear
 * then it returns the size of the bucket
 *
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::bucketSize(const KeyT &key)
{
    int index = bucketIndex(key);

    return buckets[index].size();
}

/**
 *
 *@brief takes as a parameter a key and return the size of the bucket
 * @param key the input key
 * @return returns an int .When a the value of the bucket does not appear
 * then it returns the size of the bucket
 *
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::bucketSize(const KeyT &key) const
{
    int index = bucketIndex(key);

    return buckets[index].size();
}

/**
 *@brief takes a key as input and returns the basket index.
 * @param key  the input key
 * @return the bucket index
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::bucketIndex(const KeyT &key)
{
    if (!containsKey(key))
    {
        throw BUCKET_NOT_FOUND_EXCEPTION;
    }

    return _hash(key);
}

/**
 *@brief takes a key as input and returns the basket index.
 * @param key  the input key
 * @return the bucket index
 * */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::bucketIndex(const KeyT &key) const
{
    if (!containsKey(key))
    {
        throw BUCKET_NOT_FOUND_EXCEPTION;
    }

    return _hash(key);
}

/**
 * @brief deletes all the items in the hash map
 * */
template<class KeyT, class ValueT>
void HashMap<KeyT, ValueT>::clear()
{
    totalSize = 0;
    delete[] buckets;
    buckets = new BucketCell[totalCapacity];
}


/**
 * @brief copy-constructor assigment
 * @param otherMap
 * @return the result of the assigment
 * **/
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT> &HashMap<KeyT, ValueT>::operator=(HashMap<KeyT, ValueT> const &otherMap)
{
    if (&otherMap != this)
    {

        lowerLoadFactor = otherMap.lowerLoadFactor;
        upperLoadFactor = otherMap.upperLoadFactor;

        totalSize = otherMap.totalSize;
        totalCapacity = otherMap.totalCapacity;

        delete[] buckets;

        buckets = new BucketCell[totalCapacity];

        for (int i = 0; i < totalCapacity; i++)
        {
            buckets[i] = BucketCell(otherMap.buckets[i]);
        }

    }
    return *this;
}


/**
* @brief checks whenever two sets contain the same value
 * @param otherMap
 * @return whenever the values are the same
* **/
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::operator==(HashMap<KeyT, ValueT> const &otherMap)
{

    if (totalSize != otherMap.totalSize || totalCapacity != otherMap.totalCapacity)
    {
        return false;
    }

    if (lowerLoadFactor != otherMap.lowerLoadFactor || upperLoadFactor != otherMap.upperLoadFactor)
    {
        return false;
    }

    for (int i = 0; i < totalCapacity; i++)
    {
        if (buckets[i] != otherMap.buckets[i])
        { return false; }

    }


    return true;

}

/**
* @brief checks whenever two sets contain the same value
 * @param otherMap
 * @return whenever the values are the same
* **/
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::operator==(const HashMap<KeyT, ValueT> &otherMap) const
{


    if (totalSize != otherMap.totalSize || totalCapacity != otherMap.totalCapacity)
    {
        return false;
    }

    if (lowerLoadFactor != otherMap.lowerLoadFactor || upperLoadFactor != otherMap.upperLoadFactor)
    {
        return false;
    }

    for (int i = 0; i < totalCapacity; i++)
    {
        if (buckets[i] != otherMap.buckets[i])
        {
            return false;
        }
    }

    return true;

}

/**
 * @brief checks whenever the two sets contain the same values
 * @param otherMap
 * @return whenever the values are not the same
 * */

template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::operator!=(HashMap<KeyT, ValueT> const &otherMap)
{
    return !operator==(otherMap);
}

/**
 * @brief checks whenever the two sets contain the same values
 * @param otherMap
 * @return whenever the values are not the same
 * */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::operator!=(HashMap<KeyT, ValueT> const &otherMap) const
{
    return !operator==(otherMap);
}

/**
 * Destructor
 */
template<class KeyT, class ValueT>
HashMap<KeyT, ValueT>::~HashMap()
{
    delete[] buckets;
}

/**
  * Hash function on a key
  * @param m_key
  * @return
  */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::_hash(KeyT m_key) const
{
    int v = hashFunc(m_key);
    int size = totalCapacity;
    int index = v & (size - 1);

    return index;
}

/**
  * Hash function on a key
  * @param m_key
  * @return
  */
template<class KeyT, class ValueT>
int HashMap<KeyT, ValueT>::_hash(KeyT m_key)
{
    int v = hashFunc(m_key);
    int size = totalCapacity;
    int index = v & (size - 1);

    return index;
}


/**
 * Deletes a pair in a specific bucket
 * @param key
 * @param index
 */
template<class KeyT, class ValueT>
void HashMap<KeyT, ValueT>::_deleteKeyValuePair(KeyT key, int index)
{
    int keyIndex = 0;
    while (keyIndex < buckets[index].size())
    {
        if (buckets[index][keyIndex].first == key)
        {
            buckets[index].erase(buckets[index].begin() + keyIndex);
            break;
        }
    }

}

template<class KeyT, class ValueT>
ValueT &HashMap<KeyT, ValueT>::operator[](const KeyT &key)
{

    int index = _hash(key);


    if (!_bucketContainsKey(buckets[index], key))
    {
        insert(key, ValueT());
        index = _hash(key);
    }


    return _getBucketPair(buckets[index], key).second;

}


template<class KeyT, class ValueT>
ValueT &HashMap<KeyT, ValueT>::operator[](const KeyT &key) const
{

    int index = _hash(key);


    return _getBucketPair(buckets[index], key).second;
}

/**
 * Increases or decrease  the size of the bucket array
 * @param larger
 */
template<class KeyT, class ValueT>
void HashMap<KeyT, ValueT>::_resize(bool larger)
{
    // the capacity before the _resize action
    int oldCapacity = totalCapacity;

    // the new capacity
    if (larger)
    {
        totalCapacity = totalCapacity * 2;
    }
    else
    {
        totalCapacity = totalCapacity / 2;
    }

    // a temp location  for the cells
    BucketCell *temp = new BucketCell[totalCapacity];


    for (int i = 0; i < oldCapacity; i++)
    {

        for (auto it = buckets[i].begin(); it != buckets[i].end(); it++)
        {
            int index = _hash(it->first);
            temp[index].push_back(*it);
        }

    }

    delete[] buckets;

    buckets = temp;

}

/**
  * Checks whenever a given bucket contains a key
  * @param cell
  * @param key
  * @return
  */
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::_bucketContainsKey(HashMap::BucketCell cell, const KeyT &key)
{
    bool found = false;
    int cellSize = cell.size();

    for (int i = 0; i < cellSize; i++)
    {
        if (cell[i].first == key)
        {
            found = true;
            break;
        }
    }


    return found;
}

/**
* Checks whenever a given bucket contains a key
* @param cell
* @param key
* @return
*/
template<class KeyT, class ValueT>
bool HashMap<KeyT, ValueT>::_bucketContainsKey(BucketCell cell, const KeyT &key) const
{
    bool found = false;

    for (int i = 0; i < cell.size(); i++)
    {
        if (cell[i].first == key)
        {
            found = true;
            break;
        }
    }


    return found;
}

/**
* Returns a pair from a given bucket
* @param cell
* @param key
* @return
 */
template<class KeyT, class ValueT>
std::pair<KeyT, ValueT> &HashMap<KeyT, ValueT>::_getBucketPair(HashMap::BucketCell &cell, KeyT key)
{
    int keyIndex = 0;
    int cellSize = cell.size();

    for (int i = 0; i < cellSize; i++)
    {
        if (cell[i].first == key)
        {
            keyIndex = i;
            break;
        }
    }

    return cell[keyIndex];
}

/**
* Returns a pair from a given bucket
* @param cell
* @param key
* @return
 */
template<class KeyT, class ValueT>
std::pair<KeyT, ValueT> &HashMap<KeyT, ValueT>::_getBucketPair(HashMap::BucketCell &cell, KeyT key) const
{
    int keyIndex = 0;
    int cellSize = cell.size();

    for (int i = 0; i < cellSize; i++)
    {
        if (cell[i].first == key)
        {
            keyIndex = i;
            break;
        }
    }

    return cell[keyIndex];
}

/**
 * Const forward iterator on the hash map
 * @tparam KeyT
 * @tparam ValueT
 */


template<class KeyT, class ValueT>
class HashMap<KeyT, ValueT>::iterator :
        public std::iterator<std::forward_iterator_tag, ValueT>
{
private:
    const HashMap *mp;
    int currentBucket;
    int index;
    int totalFound;
public:
    explicit iterator(const HashMap<KeyT, ValueT> *map)
    {
        mp = map;
        currentBucket = 0;
        index = 0;
        totalFound = 0;
    }

    // Iterator constructor
    iterator(const iterator &it)
    {
        mp = it.mp;
        currentBucket = it.currentBucket;
        index = it.index;
        totalFound = it.totalFound;
    }

    ~iterator()
    {}

    iterator &operator=(const iterator &other)
    {
        mp = other.mp;
        currentBucket = other.buckets;
        index = other.index;
        totalFound = other.totalFound;


        return (*this);
    }

    bool operator==(const iterator &other) const
    {

        return ((mp == other.mp) && (totalFound == other.totalFound));
    }

    bool operator!=(const iterator &other) const
    {
        return !(operator==(other));
    }


    iterator begin()
    {
        currentBucket = 0;
        index = 0;

        int capacity = mp->totalCapacity;

        // find the first non empty cell
        while ((currentBucket != capacity) && ((int) mp->buckets[currentBucket].size() == 0))
        {
            currentBucket++;
        }

        return (*this);
    }

    iterator end()
    {
        if (mp->totalSize == 0)
        {
            return begin();
        }

        currentBucket = mp->totalCapacity;
        index = 0;
        totalFound = mp->totalSize;

        return (*this);
    }

    iterator &operator++()
    {
        if (totalFound == mp->totalSize)
        {
            return (*this);
        }


        if (index < (int)mp->buckets[currentBucket].size() - 1)
        {
            index++;
            totalFound++;
        }
        else if (index == (int)mp->buckets[currentBucket].size() - 1)
        {
            index = 0;
            currentBucket++;
            totalFound++;
        }

        while ((currentBucket != mp->totalCapacity) && (int)mp->buckets[currentBucket].size() == 0)
        {
            currentBucket++;

        }
        return (*this);

    }


    iterator operator++(int)
    {

        iterator ans = *this;
        ++(*this);  // or just call operator++()
        return ans;

    }


    iterator operator+(int incr)
    {

        for (int x = 0; x < incr; ++x)
        {
            &operator++();
        }
        return (*this);
    }


    std::pair<KeyT, ValueT> &operator*()
    {
        return mp->buckets[currentBucket][index];
    }

    std::pair<KeyT, ValueT> &operator*() const
    {
        return mp->buckets[currentBucket][index];
    }

    std::pair<KeyT, ValueT> *operator->()
    {
        return &(operator*());
    }

    std::pair<KeyT, ValueT> *operator->() const
    {
        return &(operator*());
    }


};


#endif //EX3_CPP_HASHMAP_HPP