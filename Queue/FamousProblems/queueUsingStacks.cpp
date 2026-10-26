// Problem: Implement a Queue using Two Stacks

// Approach 1: Brute force (not implemented)
//             Keep everything in stack A. dequeue moves all but the last element to stack B,
//             pops the last one, then moves everything back.
//             enqueue O(1), dequeue O(n)

// Approach 2: Two stacks, pour only when B is empty
//             enqueue pushes onto A. dequeue pops from B, and only when B is empty
//             it first pours all of A into B (which reverses the order).
//             enqueue O(1), dequeue O(1) amortized, Space O(n)

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> a;                           // new elements are pushed here
    stack<int> b;                           // elements leave from here (oldest on top)

    void pourIfNeeded() {
        if (!b.empty()) {
            return;                         // B still has elements: never pour on top of them
        }
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

public:
    bool isEmpty() {
        return a.empty() && b.empty();
    }

    void enqueue(int x) {
        a.push(x);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }
        pourIfNeeded();
        cout << "Dequeued: " << b.top() << endl;
        b.pop();
    }

    void front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        pourIfNeeded();
        cout << "Front: " << b.top() << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        stack<int> tempB = b;               // copies, so the real stacks stay untouched
        stack<int> tempA = a;

        cout << "Queue (front to rear): ";

        while (!tempB.empty()) {            // B: top is the oldest, so print top to bottom
            cout << tempB.top() << " ";
            tempB.pop();
        }

        stack<int> reversed;                // A: bottom is the oldest, so reverse it first
        while (!tempA.empty()) {
            reversed.push(tempA.top());
            tempA.pop();
        }
        while (!reversed.empty()) {
            cout << reversed.top() << " ";
            reversed.pop();
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();                            // 1 2 3

    q.dequeue();                            // 1
    q.enqueue(4);
    q.display();                            // 2 3 4

    q.dequeue();                            // 2
    q.front();                              // 3
    q.dequeue();                            // 3
    q.dequeue();                            // 4

    cout << "Is empty: " << (q.isEmpty() ? "true" : "false") << endl;

    return 0;
}