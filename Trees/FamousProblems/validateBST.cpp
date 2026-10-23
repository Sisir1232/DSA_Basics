// Problem: Validate a Binary Search Tree
// Key insight: answer is that node which contains both targets as different side children 
// Approach 1: Brute force, at every node compare with the max of the left subtree
//             and the min of the right subtree (found by walking down the pointers)
//             Time O(n * h), O(n^2) , Space O(h) call stack
// Approach 2: Recursion with an allowed range (low, high) passed down
//             Time O(n), Space O(h) call stack, h = height of the tree

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Approach 1: brute force
int findMax(Node* root) {
    while (root->right != nullptr) {
        root = root->right;                     // the largest value is the rightmost node
    }
    return root->data;
}

int findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;                      // the smallest value is the leftmost node
    }
    return root->data;
}

bool checkBrute(Node* root) {
    if (root == nullptr) {
        return true;                            // empty subtree: nothing can break a rule
    }

    // check the children first: only a valid BST has its max at the far right and its min at the far left
    if (!checkBrute(root->left)) {
        return false;
    }
    if (!checkBrute(root->right)) {
        return false;
    }

    if (root->left != nullptr && findMax(root->left) >= root->data) {
        return false;                           // something in the left subtree is not smaller
    }
    if (root->right != nullptr && findMin(root->right) <= root->data) {
        return false;                           // something in the right subtree is not larger
    }

    return true;
}

void isValidBSTBrute(Node* root) {
    if (checkBrute(root)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Not a valid BST" << endl;
    }
}

// Approach 2: range check
// every value in this subtree must satisfy low < value < high
bool checkRange(Node* root, long long low, long long high) {
    if (root == nullptr) {
        return true;
    }

    if (root->data <= low || root->data >= high) {
        return false;                           // outside the range allowed by the ancestors
    }

    bool leftOk = checkRange(root->left, low, root->data);      // left side must stay below this node
    bool rightOk = checkRange(root->right, root->data, high);   // right side must stay above this node

    return leftOk && rightOk;
}

void isValidBSTRange(Node* root) {
    if (checkRange(root, LLONG_MIN, LLONG_MAX)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Not a valid BST" << endl;
    }
}

int main() {

   // creating a tree manually 

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(9);

    cout << "Brute force: ";
    isValidBSTBrute(root);

    cout << "Range check: ";
    isValidBSTRange(root);

    return 0;
}