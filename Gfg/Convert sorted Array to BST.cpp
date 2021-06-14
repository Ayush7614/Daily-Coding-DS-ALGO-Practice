//  Problem Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/


/**
Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

*/

/**
Algorithm

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
          
*/

/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

class Node 
{ 
    public:
    int data; 
    Node* left; 
    Node* right; 
}; 
  
Node* newNode(int data); 
  
Node* sortedArrayToBST(int arr[], int start, int end) 
{ 
    /* Base Case */
    if (start > end) 
    return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node *root = newNode(arr[mid]); 
  
    /* constructing the left subtree recursively and making it left child of root */
    root->left = sortedArrayToBST(arr, start, mid - 1); 
  
    /*construct the right subtree recursively  and making it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end); 
  
    return root; 
} 
  
/* Helper function that allocates a new node with the given data and NULL left and right 
pointers. */
Node* newNode(int data) 
{ 
    Node* node = new Node();
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 
  
/* A utility function to print preorder traversal of BST */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  

int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node *root = sortedArrayToBST(arr, 0, n-1); 
    cout << "PreOrder Traversal of the constructed BST is: \n"; 
    preOrder(root); 
  
    return 0; 
} 