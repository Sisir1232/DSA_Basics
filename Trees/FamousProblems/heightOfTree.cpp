// Problem: Maximum Depth (Height) of a Binary Tree
// Depth = number of nodes on the longest path from the root down to a leaf.
// Approach 1: Recursion (1 + max of the two subtree heights)
//             Time O(n), Space O(h) call stack, h = height of the tree
// Approach 2: Level-order traversal with a queue (count the levels)
//             Time O(n), Space O(w) queue, w = widest level

#include <iostream>
#include <queue>
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
int height(Node* root) {
    if (root == nullptr) {
        return 0;                               // an empty tree has height 0
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);    // this node, plus the taller subtree
}

void maxDepthRecursive(Node* root) {
    cout << "Max depth: " << height(root) << endl;
}

// Approach 2: level-order (BFS)
void maxDepthLevelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Max depth: 0" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();               // number of nodes on the current level

        for (int i = 0; i < levelSize; i++) {
            Node* cur = q.front();
            q.pop();

            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }

        depth++;                                // one full level processed
    }

    cout << "Max depth: " << depth << endl;
}

int main() {

   // creating a tree manually 

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    cout << "Recursive:   ";
    maxDepthRecursive(root);

    cout << "Level order: ";
    maxDepthLevelOrder(root);

    return 0;
}