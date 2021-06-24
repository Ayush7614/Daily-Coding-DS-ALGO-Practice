/**

Input:
1 
  \
    2
      \
        4
       /  \
      3    5

Input Format:   1 - Rootnode
               -1 - left child of 1
                2 - right child of 1
               -1 - left child of 2
                4 - right child of 2
                3 - left child of 4
               -1 - left child of 3
               -1 - right child of 3
                5 - right child of 4
               -1 - left child of 5
               -1 - right child of 5
      
Output:
Maximum value in the given Binary Tree is: 5
Minimum value in the given Binary Tree is: 1

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

template<typename T>

// A tree node
class BTNode 
{
    public:
    T data;
    BTNode *left, *right;
  
    /* Constructor that allocates a new node with the given data and NULL left and right        pointers. */
    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Returns minimum value in a given Binary Tree
int minValue(BTNode<int>* root)
{
    //Base Case
    if(root==NULL)
    return INT_MAX;
    
    // Return minimum of 3 values:
    // 1) Root's data 
    // 2) Min in Left Subtree
    // 3) Min in right subtree
    int leftmin=minValue(root->left);
    int rightmin=minValue(root->right);
    
    return min(root->data, min(leftmin,rightmin));
}

// Returns maximum value in a given Binary Tree
int maxValue(BTNode<int>* root)
{
    //Base Case
    if(root==NULL)
    return INT_MIN;
    
    // Return maximum of 3 values:
    // 1) Root's data 
    // 2) Max in Left Subtree
    // 3) Max in right subtree
    int leftmax=maxValue(root->left);
    int rightmax=maxValue(root->right);
    
    return max(root->data, max(leftmax,rightmax));
}

//Taking input recursively.
BTNode<int>* takeInput()
{
    int rootdata;
    cin>>rootdata;
    
    if(rootdata==-1)
    return NULL;
    
    BTNode<int>* root=new BTNode<int>(rootdata);
    BTNode<int>* leftchild=takeInput();
    BTNode<int>* rightchild=takeInput();
    
    root->left=leftchild;
    root->right=rightchild;
    
    return root;
}

int main()
{
    BTNode<int>* root=takeInput();
    
    cout<<"Maximum value in the given Binary Tree is: "<<maxValue(root)<<"\n";
    cout<<"Minimum value in the given Binary Tree is: "<<minValue(root)<<"\n";
}
