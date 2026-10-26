//  Implementation of Deque (double-ended queue) using a circular array
// Key insight: queue allowing insertion and deletion from both side (not LIFO)

#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front;                              // index of the first element
    int count;                              // number of elements stored

public:
    Deque() {
        front = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full, cannot insert " << x << " at front" << endl;
            return;
        }
        front = (front - 1 + MAX) % MAX;    // move front one step back (wraps around)
        arr[front] = x;
        count++;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full, cannot insert " << x << " at rear" << endl;
            return;
        }
        int rear = (front + count) % MAX;   // first free slot after the last element
        arr[rear] = x;
        count++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from front" << endl;
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        front = (front + 1) % MAX;
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from rear" << endl;
            return;
        }
        int rear = (front + count - 1) % MAX;
        cout << "Deleted from rear: " << arr[rear] << endl;
        count--;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Front: " << arr[front] << endl;
    }

    void getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        int rear = (front + count - 1) % MAX;
        cout << "Rear: " << arr[rear] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.display();                           // 1 5 10 20

    dq.deleteRear();                        // 20
    dq.deleteFront();                       // 1
    dq.display();                           // 5 10

    dq.insertRear(30);
    dq.insertRear(40);
    dq.insertRear(50);
    dq.insertRear(60);                      // full
    dq.display();                           // 5 10 30 40 50
    dq.getFront();
    dq.getRear();

    return 0;
}