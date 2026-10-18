// Implementation of queue using linked list 
// Key insight: linked list with deleteAtBeg(front) and insertAtEnd(rear) operations
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;    // acts as head of linked list 
    Node* rear;     // acts as tail of a linked list 

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {            // insertAtEnd
        Node* newNode = new Node(value);

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {                   // deleteAtBeg
        if (front == nullptr) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        // If the last node was deleted
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element: " << front->data << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
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
