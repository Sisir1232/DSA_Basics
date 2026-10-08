#include <iostream>
using namespace std;

const int SIZE = 10;    // the maximum no of elements you want to store 
int table[SIZE];        // hash table 

void initialize()
{
    for (int i = 0; i < SIZE; i++)        // -1 value act as MARK for telling this space is free 
        table[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int i = 0;

    while (table[index] != -1)          // probe to next sequence untill you find empty space 
    {
        i++;
        index = (key % SIZE + i) % SIZE;   //index of a free space 
    }

    table[index] = key;
}

bool search(int key)
{
    int index = key % SIZE;
    int start = index;           // to mark from where the probing has started 

    while (table[index] != -1)
    {
        if (table[index] == key)
            return true;

        index = (index + 1) % SIZE;     // go to next index by a linear ( unit) displacement

        if (index == start)
            break;                  // we have arrived where we began from and entired table has been searched 
    }

    return false;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
        cout << i << " -> " << table[i] << endl;
}

int main()
{
    initialize();

    insert(10);
    insert(20);
    insert(30);
    insert(25);

    display();

    int key=30;
    
    if (search(key))
        cout << key << " found" << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
// limitation of linear probing is primary clustering where consecutive occupied slots tends to form 
//the bigger the cluster gets, the more slots you have to check when a collision happens