// Implementation of Min Heap using Array
// Key insight: The parent is always smaller than or equal to its children.
// Parent of i = (i - 1) / 2
// Left child of i = 2 * i + 1
// Right child of i = 2 * i + 2

#include <iostream>
#include <climits>
using namespace std;

class MinHeap
{
    int arr[100];
    int size;

    // Restore the min-heap property downward
    void heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        // Find the smallest among the parent and existing children
        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        // If a child is smaller, swap and continue downward
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap()
    {
        size = 0;
    }

    void insert(int value)
    {
        if (size == 100)
        {
            cout << "Heap is full!" << endl;
            return;
        }

        int i = size;
        arr[i] = value;
        size++;

        // Restore the heap property upward
        while (i > 0 && arr[i] < arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int deleteMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int minValue = arr[0];

        // Replace root with last element and reduce heap size
        arr[0] = arr[size - 1];
        size--;

        // Restore the heap property downward
        if (size > 0)
            heapify(0);

        return minValue;
    }

    // Delete a specific key from the heap
    void deleteKey(int key)
    {
        int i;

        // Find the index of the intended key
        for (i = 0; i < size; i++)
        {
            if (arr[i] == key)
                break;
        }

        if (i == size)
        {
            cout << "Key not found!" << endl;
            return;
        }

        // Give the key the smallest possible integer value
        arr[i] = INT_MIN;

        // Move it upward until it reaches the root
        while (i > 0 && arr[i] < arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        // The intended key is now at the root; remove it
        deleteMin();
    }

    int getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        return arr[0];
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap h;

    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.insert(50);

    cout << "Min Heap: ";
    h.display();

    h.deleteKey(30);

    cout << "Heap after deleting 30: ";
    h.display();

    return 0;
}