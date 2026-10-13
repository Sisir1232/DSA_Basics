// Problem: Linked List Cycle
// Approach 1: Brute force (visited set)  -> Time O(n), Space O(n)
// Approach 2: Floyd's slow/fast pointers -> Time O(n), Space O(1)

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=nullptr;
    }
};

// Approach 1: remember every node (by address) we have visited
// Key insight: store the data from head somewhere one by one , if the same data come again it has cycle considering unique elements
void hasCycleBrute(Node* head) {
    unordered_set<Node*> visited;     // hash map to store the data of nodes 
    Node* temp = head;

    while (temp != nullptr) {
        if (visited.count(temp) == 1) {     // seen this exact node before
            cout << "Cycle found" << endl;
            return;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    cout << "No cycle" << endl;             // reached nullptr
}

// Approach 2: Floyd's algorithm, no extra memory
   //Key insight: if you have two different speed of two pointers starting at same node, then they will eventually meet in a cycle

void hasCycleFloyd(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {   // check both before fast->next->next
        slow = slow->next;                  // 1 step
        fast = fast->next->next;            // 2 steps
        if (slow == fast) {                 // they met inside the loop
            cout << "Cycle found" << endl;
            return;
        }
    }
    cout << "No cycle" << endl;             // fast reached the end
}

int main() {
    // build 1 -> 2 -> 3 -> 4, then point 4 back to 2
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // create a links to create a cycle of nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;                         

    cout << "Brute force: ";
    hasCycleBrute(n1);

    cout << "Floyd's:     ";
    hasCycleFloyd(n1);

    return 0;
}