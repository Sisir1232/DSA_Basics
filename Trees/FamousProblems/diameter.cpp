// finding diameter of a given binary tree 
// diameter: maximum no of edge between two leaf nodes 
// key insight: we already have find max no of edges in left and right subtree of a node in height function
         //   : adding them gives the no of edges in the path 
         //   : compare with each path making each node as the central 
         
#include <iostream>
#include <algorithm>
using namespace std;

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

class BinaryTree
{
public:
    // Method 1: Brute Force
    int height(Node* root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterBruteForce(Node* root)
    {
        if (root == nullptr)
            return 0;

        // Diameter passing through the current node
        int currentDiameter = height(root->left) + height(root->right);

        // Diameter entirely inside either subtree
        int leftDiameter = diameterBruteForce(root->left);
        int rightDiameter = diameterBruteForce(root->right);

        return max({currentDiameter, leftDiameter, rightDiameter});
    }

    // Method 2: Optimized
    int heightOptimized(Node* root, int& dia)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = heightOptimized(root->left, dia);
        int rightHeight = heightOptimized(root->right, dia);

        dia = max(dia, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOptimized(Node* root)
    {
        int dia = 0;
        heightOptimized(root, dia);
        return dia;
    }
};

int main()
{
    BinaryTree tree;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    cout << "Brute Force Diameter: "
         << tree.diameterBruteForce(root) << endl;

    cout << "Optimized Diameter: "
         << tree.diameterOptimized(root) << endl;

    return 0;
}
