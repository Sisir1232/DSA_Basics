// Implementation of Binary Search Tree including insertion, creation,
// deletion, searching and traversals

// Key insights:
// In linked list, one data points to another data and creates a link.
// In a tree, one node can point to different nodes, creating a child-parent relationship.
// In a Binary Search Tree, a node can have a maximum of 2 children.

#include <iostream>
using namespace std;

class BST
{
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        Node(int value)
        {
            data = value;
            left = right = nullptr;
        }
    };

    Node* root;

    // Insert a node recursively
    Node* insert(Node* node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // Search for a value recursively
    bool search(Node* node, int value)
    {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    // Find the smallest node in a subtree
    Node* findMin(Node* node)
    {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    // Delete a node recursively
    Node* deleteNode(Node* node, int value)
    {
        if (node == nullptr)
            return nullptr;

        // Find the node whose value is to be deleted
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else
        {
            // Case 1: No left child
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: No right child
            if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            // Replace with inorder successor (minimum in right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Inorder: Left -> Root -> Right
    void inorder(Node* node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder: Root -> Left -> Right
    void preorder(Node* node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder: Left -> Right -> Root
    void postorder(Node* node)
    {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST()
    {
        root = nullptr;
    }

    // Create the BST by inserting initial values
    void create(int values[], int size)
    {
        for (int i = 0; i < size; i++)
            root = insert(root, values[i]);
    }

    // Public insertion method
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Public searching method
    bool search(int value)
    {
        return search(root, value);
    }

    // Public deletion method
    void deletion(int value)
    {
        root = deleteNode(root, value);
    }

    // Public traversal methods
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    void preorder()
    {
        preorder(root);
        cout << endl;
    }

    void postorder()
    {
        postorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    tree.create(values, 7);
    tree.insert(25);
    tree.deletion(30);

    if (tree.search(60))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    return 0;
}