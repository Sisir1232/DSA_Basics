// Implementation of linear queue using array 
// Queue follow LIFO principle where we insert and delete the datas from opposite side 

#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;     // front represents the index pointer for next deletion (dequeue)
                         // rear represents the index pointer for latest insertion( enqueue)
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;          // if the inserted value is first , front needs to be initiazed
        }
        arr[++rear] = value;
    }                                                // Time complexity:O(1) 

    void dequeue() {
        if (front == -1 || front > rear) {       
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted: " << arr[front++] << endl;
    }                                                // Time complexity:O(1) 

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;    // Time complexity:O(1) 
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }                                             // Time complexity:O(n) 
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}
