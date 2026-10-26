// Implementation of circular queue using array 
// key insight: linear queue with wrap around feature where after rear reaches (SIZE-1), rear wraps back to 0, 1, 2..(front)
         //  : if elements were dequeued and space were left on early indices
         //  : use of % operator to achieve wrap around condition

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        // Queue is full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Overflow" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
    }                                             // Time complexity:O(1) 

    void dequeue() {
        // Queue is empty
        if (front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Only one element was present
        if (front == rear) {
            front = rear = -1;            // resetting the pointers
        } else {
            front = (front + 1) % SIZE;
        }                                       // Time complexity:O(1) 
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }                                                     // Time complexity:O(1) 

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;

        while (true) {              // SIZE no longer helps to terminate the condition
            cout << arr[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }                                  // Time complexity:O(n) 
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    q.peek();

    return 0;
}

// Circular queue was used to overcome following limitation of linear queue 
    // 1. dequeue element 's memory space are wasted and can't be reused 
    // 2. False overflow warning: even though there is space in dequeued early indices , it gives overflow on rear=SIZE-1