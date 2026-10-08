#include <iostream>
#include <list>         // doubly linked list 
using namespace std;

const int SIZE = 10;

list<int> table[SIZE];      // array of a linked list 

void insert(int key)
{
    int index = key % SIZE;            // calculating indexes of hash table based on LSB of a number 
    table[index].push_back(key);        // storing the key on that calculated index of a hash table
}

bool search(int key)
{
    int index = key % SIZE;             // looking which index does they key belongs to

    for (int value : table[index])
    {
        if (value == key)               //time complexity goes to O(n) if all array member has same LSB
            return true;                // in such case use 2nd LSB by using hash function as (key/10)%10
    }                                    // the key insight is to uniformly distribute the array members

    return false;                        
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> ";

        for (int value : table[i])
            cout << value << " -> ";

        cout << "NULL"<<endl;
    }
}

int main()
{
    insert(10);
    insert(15);
    insert(7);
    insert(20);
    insert(12);
    insert(25);

    display();

    int key=7;
    if (search(key))
        cout << key << " found"<<endl;
    else
        cout << key << " not found"<<endl;

    return 0;
}