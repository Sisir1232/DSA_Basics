// Implementation of priority queue using array 
// Key insight: datas are inserted one by one with its priority and deleted in order of the priority not LIFO
#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue {
private:
    int arr[SIZE];
    int priority[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;   // to count no of data
    }

    void enqueue(int value, int p) {
        if (count == SIZE) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[count] = value;
        priority[count] = p;
        count++;
    }                                          // Time complexity:O(1) 

    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow" << endl;
            return;
        }

        // Find the element with the highest priority
        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }                                            

        cout << "Deleted: " << arr[highest] << endl;

        // Shift remaining elements left to prevent gaps between data
        for (int i = highest; i < count - 1; i++) {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }

        count--;  // since data is deleted
    }                                             // Time complexity:O(n) 

    void peek() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }

        cout << "Highest priority element: "
             << arr[highest] << endl;
    }                                            // Time complexity:O(n) 

    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "(" << arr[i]
                 << ", priority " << priority[i] << ") ";
        }

        cout << endl;
    }                                              // Time complexity:O(n) 
};

int main() {
    PriorityQueue q;

    q.enqueue(10, 3);
    q.enqueue(20, 1);
    q.enqueue(30, 2);
    q.enqueue(40, 1);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}
