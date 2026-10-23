// Problem: Lowest Common Ancestor of a BST
// Approach 1: Recursion using the BST ordering
//             both smaller -> recurse left, both larger -> recurse right, otherwise this node is the LCA
//             Time O(h), Space O(h) call stack, h = height of the tree
// Approach 2: The same idea as a loop (single walk down from the root)
//             Time O(h), Space O(1)

#include <iostream>
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

// Approach 1: recursion
Node* findLCA(Node* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (p < root->data && q < root->data) {
        return findLCA(root->left, p, q);       // both are in the left subtree
    }

    if (p > root->data && q > root->data) {
        return findLCA(root->right, p, q);      // both are in the right subtree
    }

    return root;                                // they split here, or one of them is this node
}

void lcaRecursive(Node* root, int p, int q) {
    Node* lca = findLCA(root, p, q);

    if (lca == nullptr) {
        cout << "No LCA (empty tree)" << endl;
    }
    else {
        cout << "LCA: " << lca->data << endl;
    }
}

// Approach 2: iterative
void lcaWalk(Node* root, int p, int q) {
    Node* cur = root;

    while (cur != nullptr) {
        if (p < cur->data && q < cur->data) {
            cur = cur->left;
        }
        else if (p > cur->data && q > cur->data) {
            cur = cur->right;
        }
        else {
            cout << "LCA: " << cur->data << endl;
            return;
        }
    }
}

int main() {
    
   // creating BST manually 

    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    int p = 3;
    int q = 5;

    cout << "Recursive: ";
    lcaRecursive(root, p, q);

    cout << "Iterative: ";
    lcaWalk(root, p, q);

    return 0;
}