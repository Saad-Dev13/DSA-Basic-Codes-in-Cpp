#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        // Initialize the hash table with -1 (indicating empty)
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = -1;
        }
    }

    // Hash Function (Simple modulus hashing)
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing to handle collisions
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
        cout << "Key " << key << " inserted at index " << index << endl;
    }

    // Search for a key in the hash table
    int search(int key) {
        int index = hashFunction(key);

        // Linear probing to find the key
        while (table[index] != key) {
            if (table[index] == -1) {
                return -1;  // Key not found
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return index;  // Return index where key is found
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myHashTable;

    myHashTable.insert(5);
    myHashTable.insert(15);
    myHashTable.insert(25);
    myHashTable.insert(35);
    myHashTable.insert(45);
    myHashTable.insert(55);

    myHashTable.display();

    int searchKey;
    cout << "\nEnter a key to search: ";
    cin >> searchKey;

    int result = myHashTable.search(searchKey);

    if (result != -1) {
        cout << "Key " << searchKey << " found at index " << result << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    return 0;
}
