#include <iostream>
#include <vector>
using namespace std;

// Node for hash table values
struct HashNode {
    int key;
    int value;
    HashNode* next;
    int hash_index;

    // constructor
    HashNode(int key, int value, int hash_index) :
        key(key), value(value), next(nullptr), hash_index(hash_index) {}
};


// HashTable class
class HashTable {
    private:
    int table_size;
    vector<HashNode*> table;

    // hash function
    // gives hash_index in the hash table for a given key
    int hashFunction(int key) {
        return key % table_size;
    }

    public:
    // constructor
    HashTable(int table_size) : table_size(table_size) {
        table.resize(table_size, nullptr);
    }

    // method to insert nodes
    HashNode* insertNode(int key, int value) {
        // calculate the hash index
        int hash_index = hashFunction(key);

        HashNode* hash_node = new HashNode(key, value, hash_index);

        // if no collision
        if (table[hash_index] == nullptr) {
            table[hash_index] = hash_node;
            return hash_node;
        }

        // if collision
        else {
            HashNode* temp = table[hash_index];
            while(temp->next != nullptr) {
                temp = temp-> next;
            }
            temp->next = hash_node;
            return hash_node;
        }
    }

    // search key
    HashNode* searchKey(int key) {
        int hash_index = hashFunction(key);

        // if index has nodes
        if(table[hash_index] != nullptr) {
            HashNode* temp = table[hash_index];
            HashNode* prev = nullptr;
            while(temp != nullptr) {
                // if key found
                if (temp->key == key) {
                    return temp;
                }
                prev = temp;
                temp = temp->next;
            }
            // key not found
            return nullptr;
        }

        // no nodes at index
        return nullptr;
    }


    // remove key
    bool removeKey(int key) {
        int hash_index = hashFunction(key);

        // if collision - possibility of key being present
        if (table[hash_index] != nullptr) {
            HashNode* temp = table[hash_index];
            HashNode* prev = nullptr;

            while (temp != nullptr) {
                // if first node
                if (temp->key == key) {
                    if (prev == nullptr) 
                        table[hash_index] = temp->next;
                    else
                        prev->next = temp->next;
                    delete temp;
                    return true;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        // if key is not present in the hash table
        return false;
    }



};


int main() {
    HashTable hash_table(5);

    hash_table.insertNode(1, 10);
    hash_table.insertNode(2, 20);
    hash_table.insertNode(3, 30);
    hash_table.insertNode(4, 40);
    hash_table.insertNode(5, 50);
    hash_table.insertNode(6, 60);
    hash_table.insertNode(7, 70);
    hash_table.insertNode(8, 80);
    hash_table.insertNode(9, 90);
    hash_table.insertNode(10, 100);
    hash_table.insertNode(11, 110);
    hash_table.insertNode(12, 120);

    // searching for a key
    int key = 8;
    HashNode* hash_node = hash_table.searchKey(key);
    if (hash_node != nullptr)
        cout << "Key: " << hash_node->key << ", Value: " << hash_node->value << " at Index: " << hash_node->hash_index << endl;
    else
        cout << "Key: " << key << " not found" << endl;

    // removing a key
    key = 8;
    if (hash_table.removeKey(key))
        cout << "Key: " << key << " removed" << endl;
    else
        cout << "Key: " << key << " not found" << endl;

    // confirming removal
    hash_node = hash_table.searchKey(key);
    if (hash_node != nullptr)
        cout << "Key: " << hash_node->key << ", Value: " << hash_node->value << " at Index: " << hash_node->hash_index << endl;
    else
        cout << "Key: " << key << " not found" << endl;

    return 0;
}