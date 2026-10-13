// Problem: Reorder List  (L0 -> Ln -> L1 -> Ln-1 -> ...)
// Approach 1: Array of values, overwrite data in new order      -> Time O(n), Space O(n)
//             (changes values, not links: not accepted if the problem forbids it)
// Approach 2: Middle + reverse second half + merge alternately  -> Time O(n), Space O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=nullptr;
    }
};

Node* buildList(int n) {                    // builds 1 -> 2 -> ... -> n
    Node* head = new Node(1);
    Node* t = head;
    for (int v = 2; v <= n; v++) {
        t->next = new Node(v);
        t = t->next;
    }
    return head;
}

void printList(Node* head) {
    for (Node* t = head; t != nullptr; t = t->next){
         cout << t->data << " -> ";
    }
    cout << "NULL" << endl;
}

// Approach 1: brute force by copying the values into an array
void reorderBrute(Node* head) {
    if (head == nullptr) return;

    int n = 0;                              // pass 1: count the nodes
    for (Node* t = head; t != nullptr; t = t->next) n++;

    int* vals = new int[n];   // dynamic array to store the values 
    int k = 0;
    for (Node* t = head; t != nullptr; t = t->next) vals[k++] = t->data;   // pass 2: copy values

    int i = 0, j = n - 1;                   // i = front index, j = back index
    Node* t = head;
    while (t != nullptr) {                  // pass 3: overwrite values in the new order
        t->data = vals[i++];                // front value
        t = t->next;
        if (t == nullptr) break;            // odd length: no node left for a back value
        t->data = vals[j--];                // back value
        t = t->next;
    }

    delete[] vals;
}

//  reverse a list, return the new head
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Approach 2: optimal
void reorderOptimal(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    // Step 1: find the end of the first half (slow stops on the first middle)
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: cut the list, then reverse the second half
    Node* second = reverseList(slow->next);
    slow->next = nullptr;                   // first half now ends here

    // Step 3: merge, one node from each list in turn
    Node* first = head;
    while (second != nullptr) {
        Node* t1 = first->next;             // save both next pointers before overwriting
        Node* t2 = second->next;

        first->next = second;
        second->next = t1;

        first = t1;
        second = t2;
    }
}

int main() {
    Node* a = buildList(5);
    reorderBrute(a);
    cout << "Brute force: ";
    printList(a);

    Node* b = buildList(5);
    reorderOptimal(b);
    cout << "Optimal:     ";
    printList(b);

    return 0;
}