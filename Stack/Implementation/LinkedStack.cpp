// Implementation using linked list: creating a node in runtime and storing/deleting the datas as per operation
                               //  : using insertAtBeg and deleteAtBeg as push and pop and using head pointer only as tos

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

class Stack {
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }                                        // Time complexity:O(1)                                        

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->data << endl;

        top = top->next;
        delete temp; // actually deletes the data unlike in array implementation
    }                                             
                                           // Time complexity:O(1)

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Stack() {                 // destructor to delete the stack when it goes out of scope
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.peek();
    s.pop();
    s.display();

    return 0;
}

// The main DIFFERENCE with array implementation is that this stack is dynamic in nature 
// allowing memory allocation and deallocation for insertion and deletion of datas in runtime(heap)