// Implementation of self balanced AVL Tree 
// Key insight: Upon inserting the node, if it becomes skewed ( bf=2), then rotate the nodes accordingly
   // Types of rotation: LL , RR , LR, RL 
   
#include <iostream>
#include <algorithm>
using namespace std;

class AVL
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int height;     // to check tree is balanced or not 

        Node(int value)
        {
            data = value;
            left = right = nullptr;
            height = 1;
        }
    };

    Node *root = nullptr;

    // Find the height of a node
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    // Balance Factor = Left Height - Right Height
    int balanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;

        return height(node->left) - height(node->right);
    }

    // Update the height of a node
    void updateHeight(Node *node)
    {
        node->height = 1 + max(height(node->left),
                               height(node->right));
    }

    // Right rotation
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotation
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert a node and restore balance
    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate values are not allowed

        updateHeight(node);

        int balance = balanceFactor(node);

        // LL Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find the smallest node in a subtree
    Node *minimumNode(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    // Delete a node and restore balance
    Node *deleteNode(Node *node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else
        {
            // Node has zero or one child
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *child = node->left ? node->left : node->right;

                if (child == nullptr)
                {
                    delete node;
                    return nullptr;
                }

                Node *temp = node;
                node = child;
                delete temp;
            }
            else
            {
                // Replace with inorder successor
                Node *temp = minimumNode(node->right);

                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        // LL Case
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rightRotate(node);

        // LR Case
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR Case
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return leftRotate(node);

        // RL Case
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
public:
    void insert(int value)
    {
        root = insert(root, value);
    }

    void deleteValue(int value)
    {
        root = deleteNode(root, value);
    }

};

int main()
{
    AVL tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(40);
    tree.insert(50);

    tree.deleteValue(20);
    return 0;
}
