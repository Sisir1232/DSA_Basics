// Problem: Middle of the Linked List
// Approach 1: Count, then walk n/2 steps -> Time O(n), Space O(1), ~1.5 passes
// Approach 2: Slow/fast pointers         -> Time O(n), Space O(1), one pass
  
// :While fast moves to nullptr , slow moves to n/2 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Approach 1: count the nodes, then walk n/2 steps
void middleCount(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    int n = 0;
    for (Node* t = head; t != nullptr; t = t->next) n++;

    Node* temp = head;
    for (int i = 0; i < n / 2; i++) temp = temp->next;
    cout << "Middle: " << temp->data << endl;
}

// Approach 2: slow/fast pointers
void middleSlowFast(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {   
        slow = slow->next;              // 1 step
        fast = fast->next->next;        // 2 steps
    }
    cout << "Middle: " << slow->data << endl;
}

int main() {
    // build 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    Node* t = head;
    for (int v = 2; v <= 6; v++) {
        t->next = new Node(v);
        t = t->next;
    }

    cout << "Count method:     ";
    middleCount(head);

    cout << "Slow/fast method: ";
    middleSlowFast(head);

    return 0;
}