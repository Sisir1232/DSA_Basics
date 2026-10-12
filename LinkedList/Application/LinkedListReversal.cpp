// Reversal of a singly linked list
// approach 1 (brute force): 3 passes + extra array -> O(n) time, O(n) space
// approach 2 (optimal): three pointers, reuse the same nodes -> O(n) time, O(1) space

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
    Node *head, *tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Brute Force approach
    void reverseBrute() {
        if (head == nullptr) return;

        // Pass 1: count the nodes
        int n = 0;
        Node* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int* arr = new int[n];                // extra space: O(n)

        // Pass 2: copy the values into the array
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            arr[i] = temp->data;
            i++;
            temp = temp->next;
        }

        // Pass 3: write the values back, starting from the end of the array
        temp = head;
        i = n - 1;
        while (temp != nullptr) {
            temp->data = arr[i];
            i--;
            temp = temp->next;
        }

        delete[] arr;                         // free the extra space
    }

    // optimal method using pointers
    void reverse() {
        Node* prev = nullptr;     // node behind curr (first node's next must become nullptr)
        Node* curr = head;        // node we're standing on
        Node* next = nullptr;     // saved link to the node ahead

        tail = head;              // old head becomes the new tail

        while (curr != nullptr) {
            next = curr->next;    // 1. save the node ahead before touching any arrow
            curr->next = prev;    // 2. flip the arrow backward
            prev = curr;          // 3. save the current which can used in next iteration
            curr = next;
        }

        head = prev;              // prev is left on the last node, which is the new head
    }
};

int main() {
    LinkedList list1, list2;

    for (int i = 1; i <= 5; i++) {
        list1.insertAtEnd(i);
        list2.insertAtEnd(i);
    }

    cout << "Original:             ";
    list1.display();

    list1.reverseBrute();
    cout << "Brute force reversed:";
    list1.display();

    list2.reverse();
    cout << "Pointer approach reversed:";
    list2.display();

    return 0;
}