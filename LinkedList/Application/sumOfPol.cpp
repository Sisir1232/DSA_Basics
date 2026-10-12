// Addition of two polynomial equation 
// keysight: we need two variables under single entity( coff, exp) : struct plays a role here 
          //: we need another class to manages these individual entity to make a eqn : linkedlist plays a role here 
// since it requires two integer data variables inside a node, STL library doesn't help here 

#include <iostream>
using namespace std;

struct Node {
    int coff, exp;
    Node* next;

    Node(int c, int e) {
        coff = c;
        exp = e;
        next = nullptr;
    }
};

class LinkedList {
    Node *head, *tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    void insert(int coff, int exp) {          // datas are inserted in descending order of exp 
        Node* newNode = new Node(coff, exp);  // you can use insertAtBeg if datas are inserted in ascending order 

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
            cout << "|" << temp->coff
                 << "|" << temp->exp << "| -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    Node* getHead() {
        return head;
    }
};

LinkedList addPol(LinkedList P, LinkedList Q) {   // accepts two pol eqn and generate a new one representing sum
    Node* p = P.getHead();     // to traverse the linkedlists accessing its indivudual coff and exp
    Node* q = Q.getHead();

    LinkedList pol3;

    while (p != nullptr && q != nullptr) {
        if (p->exp > q->exp) {
            pol3.insert(p->coff, p->exp);        // if exp is higher than rest , no chance of addition
            p = p->next;                         // there is a chance Q pol eqn's q entity ( lesser exp one)
                                                 // will be added to next p's coff
        }
        else if (p->exp < q->exp) {
            pol3.insert(q->coff, q->exp);
            q = q->next;
        }
        else {
            pol3.insert(p->coff + q->coff, p->exp);
            p = p->next;
            q = q->next;
        }
    }

    // Copy remaining terms of P
    while (p != nullptr) {
        pol3.insert(p->coff, p->exp);
        p = p->next;
    }

    // Copy remaining terms of Q
    while (q != nullptr) {
        pol3.insert(q->coff, q->exp);
        q = q->next;
    }

    return pol3;
}

int main() {
    LinkedList pol1, pol2;

    // pol1: 5x^4 + 3x^2 - 2x + 7
    pol1.insert(5, 4);
    pol1.insert(3, 2);
    pol1.insert(-2, 1);
    pol1.insert(7, 0);

    // pol2: 6x^5 + 4x^2 - 5x + 10
    pol2.insert(6, 5);
    pol2.insert(4, 2);
    pol2.insert(-5, 1);
    pol2.insert(10, 0);

    LinkedList polS = addPol(pol1, pol2);

    cout << "Polynomial 1: ";
    pol1.display();

    cout << "Polynomial 2: ";
    pol2.display();

    cout << "Sum: ";
    polS.display();

    return 0;
}
// Time complexity: O(n+m ) ( every node in both linked list is visited once)
// Space complexity O(n+m) ( total space )   
// worst case: every exp is distinct from each other
// where n and m and no of nodes in pol1 and pol2 respectively