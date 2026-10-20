// Implementation of Binary Search Tree including insertion , creation , deletion, searching and traversals
// Key insights: In linked list , one data points to another data and creates a link.... 
            // : To extend this relationship , in tree one node can point to different nodes creating a child-parent relationship
            // : In Binary Search Tree, the no of child a node can have is MAX 2 

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

    // Insert a node recursively ... search the suitable position in which node follows < > relationship
    Node* insert(Node* node, int value)
    {
        if (node == nullptr)        // first node to the tree 
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
     // Find a node whose value is desired to be deleted 
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
            // Here we can either find min from right subtree (sucessor) or max from left subtree (predecessor)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
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
   
// The reason why we need indirect recurison is because for first recursive call we need to send the root 
// And if we use default arg , there is no recursion 
// so either create a different method or pass it in main function in arg 

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

    return 0;
}