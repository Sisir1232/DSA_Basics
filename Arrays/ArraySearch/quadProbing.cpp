#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int i = 0;

    while (table[index] != -1)
    {
        i++;
        index = (key % SIZE + i * i) % SIZE;    // instead of looking for next index , positions are incremented in a quadradic way  
    }

    table[index] = key;
}

bool search(int key)
{
    int originalIndex = key % SIZE;
    int index = originalIndex;
    int i = 0;

    while (table[index] != -1)
    {
        if (table[index] == key)
            return true;

        i++;
        index = (originalIndex + i * i) % SIZE;

        if (index == originalIndex)
            break;
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
    insert(40);

    display();

    int key;
    
    if (search(key))
        cout << key << " found" << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
// limitation of quadradic probing is secondary clustering where keys with same value follows same probe sequence
// Hash table still has empty space, but quadratic probing cannot find an empty position for a particular key