#include <iostream>
#include "HashTable.h"

using namespace std;
    
int HashTable::hash(int val) {
    return val % size;
}

HashTable::HashTable(int s) {
    table.resize(s);
    size = s;
}
    
void HashTable::insert(int val) {
    int index = hash(val);
    Node *node = new Node(val);
    if (table[index] == NULL) {
        table[index] = node;
    } else {
        Node *curr = table[index];
        while (curr->next != NULL) {
            curr->next->val = curr->val;
        }
        curr->next = node;
    }
}
     
bool HashTable::contains(int val) {
    int index = hash(val);
        
    Node *curr = table[index];
    while (curr != NULL) {
        if (curr->val == val) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
    
void HashTable::printTable() {
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        Node *curr = table[i];
        while (curr != NULL) {
            cout << curr->val << "-> ";
            curr = curr->next;
        }
        cout << endl;
    }
}  
