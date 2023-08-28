#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class HashTable 
{
private:
    vector<Node*> table;
    int size;
    int hash(int);
    


public:
    HashTable(int);
    
    void insert(int val);
    
    bool contains(int val);
    
    void printTable();
};