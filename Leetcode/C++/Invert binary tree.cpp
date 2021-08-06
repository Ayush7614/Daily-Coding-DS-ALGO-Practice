//LINK TO THE QUESTION: https://leetcode.com/problems/invert-binary-tree/
/*
QUESTION STATEMENT:Given the root of a binary tree, invert the tree, and return its root.


//AIM: invert the tree,and return its root.
//Example:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
*/


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
 
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
 
// Function to invert a given binary tree using preorder traversal
    void swap(TreeNode* root)
    {
        if(root==NULL)
            return;
        swap(root->left);
        swap(root->right);
        TreeNode* n;
        n=root->left;
        root->left=root->right;
        root->right=n;
    }
    TreeNode* invertTree(TreeNode* root) {
      swap(root);
        return root;
    }

int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    swap(root);
    preorder(root);
 
    return 0;
}