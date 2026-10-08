#include <iostream>
using namespace std;

const int SIZE = 10;
const int R = 7;// keep it a prime number less than SIZE 

int table[SIZE];

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)             // it helps ensure the probe sequence can reach all table positions 
{
    return R - (key % R);      // alternative: 1+ key % SIZE-1  with SIZE being prime 
}

void insert(int key)
{
    int index = hash1(key);
    int i = 0;

    while (table[index] != -1)
    {
        i++;
        index = (hash1(key) + i * hash2(key)) % SIZE;
    }

    table[index] = key;
}

bool search(int key)
{
    int index = hash1(key);
    int i = 0;

    while (table[index] != -1)
    {
        if (table[index] == key)
            return true;

        i++;
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (i == SIZE)
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
    insert(25);

    display();

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    if (search(key))
        cout << key << " found" << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
// it removes the limitation of quadradic hasing by introducing second hash function which makes probing 
// sequence to visit all the positions and if empty storing the value 