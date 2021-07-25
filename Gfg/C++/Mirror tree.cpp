//LINK TO THE QUESTION:
/*
https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
*/
//SOLUTION:
#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Function to perform preorder traversal on a given binary tree
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
 
// Function to convert a given binary tree into its mirror
bool convertToMirror(Node* root)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // converting left subtree
    convertToMirror(root->left);
 
    // converting right subtree
    convertToMirror(root->right);
 
    // swapping left subtree with right subtree
    swap(root->left, root->right);
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    convertToMirror(root);
    preorder(root);
 
    return 0;
}


