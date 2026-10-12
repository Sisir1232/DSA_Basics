// Multiplication of two polynomial equation
// idea: multiply whole P with one term of Q -> this gives a list already in descending order of exp
//       then add that partial list to the result using addPol, repeat for every term of Q

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
        Node* newNode = new Node(coff, exp);

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

LinkedList addPol(LinkedList P, LinkedList Q) {   // same as before 
    Node* p = P.getHead();
    Node* q = Q.getHead();

    LinkedList pol3;

    while (p != nullptr && q != nullptr) {
        if (p->exp > q->exp) {
            pol3.insert(p->coff, p->exp);
            p = p->next;
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

LinkedList mulPol(LinkedList P, LinkedList Q) {   // accepts two pol eqn and generate a new one representing product
    Node* q = Q.getHead();

    LinkedList result;                            // starts empty, grows after every term of Q

    while (q != nullptr) {
        LinkedList partial;                       // P * (one term of Q)
        Node* p = P.getHead();

        while (p != nullptr) {
            partial.insert(p->coff * q->coff, p->exp + q->exp);   // coff multiplies, exp adds
            p = p->next;
        }

        result = addPol(result, partial);         // merge partial into result, same exp gets added
        q = q->next;
    }

    return result;
}

int main() {
    LinkedList pol1, pol2;

    // pol1: 5x^5 + 3x^3 + x + 1
    pol1.insert(5, 5);
    pol1.insert(3, 3);
    pol1.insert(1, 1);
    pol1.insert(1, 0);

    // pol2: 5x^5 + 4x^4 + 2x^2 + 1
    pol2.insert(5, 5);
    pol2.insert(4, 4);
    pol2.insert(2, 2);
    pol2.insert(1, 0);

    LinkedList polM = mulPol(pol1, pol2);

    cout << "Polynomial 1: ";
    pol1.display();

    cout << "Polynomial 2: ";
    pol2.display();

    cout << "Product: ";
    polM.display();

    return 0;
}

// Time complexity: O(km^2 )
// Space complexity O(nm) ( total space )   
// worst case: no merging happens 
// where n and m and no of nodes in pol1 and pol2 respectively