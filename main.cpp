#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    
    cout << "Hash Table:" << endl;
    ht.printTable();
    
    int val;
    cout << "Enter a value to search for: ";
    cin >> val;
    if (ht.contains(val)) {
        cout << val << " was found in the hash table." << endl;
    } else {
        cout << val << " was not found in the hash table." << endl;
    }
    
    return 0;
}