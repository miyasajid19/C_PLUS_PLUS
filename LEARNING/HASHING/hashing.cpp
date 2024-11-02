#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm> // Include for std::find

using namespace std;

class Hashing
{
    vector<list<int>> hashtable;
    int size;

public:
    Hashing(int size)
    {
        this->size = size;
        this->hashtable.resize(size);
    }

    int hashValue(int key)
    {
        return key % this->size;
    }

    void addKey(int key)
    {
        int index = hashValue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator searchKey(int key)
    {
        int index = hashValue(key);
        return find(hashtable[index].begin(), hashtable[index].end(), key);
    }

    bool keyExists(int key)
    {
        int index = hashValue(key);
        return searchKey(key) != hashtable[index].end();
    }

    void Delete(int key)
    {
        int index = hashValue(key);
        auto it = searchKey(key);
        if (it != hashtable[index].end()) // key is present
        {
            hashtable[index].erase(it);
            cout << "Key " << key << " has been deleted" << endl;
        }
        else
        {
            cout << "Key " << key << " not found" << endl;
        }
    }
};

int main()
{
    // Example usage:
    Hashing hashTable(10);
    hashTable.addKey(15);
    hashTable.addKey(25);

    int searchKey = 10;
    if (hashTable.keyExists(searchKey))
    {
        cout << "Key " << searchKey << " found in the hash table." << endl;
    }
    else
    {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    hashTable.Delete(15);
    hashTable.Delete(30);

    return EXIT_SUCCESS;
}
