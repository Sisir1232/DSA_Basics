// Stack Implementation
// stack follow LIFO/FILO principle - data is inserted and and deleted from same side
                              //    - only one pointer (TOS) is used to maintain the insertion and deletion
// Implementation using array: use array as  stack where you can insert and access into last array index only (TOS)                                            

#include <iostream>
using namespace std;

#define SIZE 5       // stack has maximum size of 5 

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;    //returns true if empty 
    }

    bool isFull() {
        return top == SIZE - 1;   // returns true if all array slots are occupied
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++top] = value;
    }                                                //Time complexity:O(1)

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Popped: " << arr[top--] << endl;
    }                                                 //Time complexity:O(1)                                           

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }                                                  // Time complexity:O(1)

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }                                                  //Time complexity:O(n)
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
