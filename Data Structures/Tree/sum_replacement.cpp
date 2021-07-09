/*
CODE DESCRIPTION->
- A binary tree is a tree-type non-linear data structure with a 
  maximum of two child nodes for each parent node. 
- Every node in a binary tree has:
        i) node data
        ii) a left child and 
        iii) a right child  
- The top node of a tree is called the root node.
- Nodes which don't have both left and right child is called leaf node.

Here,
- We are given a binary tree where each node has +ve and -ve values. 
- We need to convert this to a tree where each node contains,
              sum of its left subtree + right subtree + particular node data.
- The values of leaf nodes remain unchanged.

Example,
Input::
       11
      /  \
     2   -22
    / \    
   4   -5    

Output::
       -10
      /   \
     1    -22
    / \    
   4   -5
*/

#include<iostream>
using namespace std;

/* TREE STRUCTURE */
struct node
{
  struct node *lc;
  int data;
  struct node *rc;
  struct node *status;
};

/* TREE CREATION */
struct node* create(int t)
{
  struct node *temp=new (struct node);
  temp->data=t;
  temp->lc=temp->rc=NULL;
  return temp;
}

/* INORDER TRAVERSAL WITH RECURSION */
void inorder_rec(struct node *temp)
{
  if(temp==NULL)
  return;
  inorder_rec(temp->lc);
  cout<<temp->data<<"   ";
  inorder_rec(temp->rc);
}

/* SUM REPLACEMENT RECURSIVE FUNCTION */
void sum_replacement(struct node *temp){
  /* base condition */
  if(temp==NULL)
  return;

  /* calling sum_replacement recursive function for left subtree */
  sum_replacement(temp->lc);
  /* calling sum_replacement recursive function for right subtree */
  sum_replacement(temp->rc);

  /* if temp is having left node we update data of temp with temp->data + temp->lc->data */
  if(temp->lc!=NULL)
  temp->data+=temp->lc->data;

  /* if temp is having right node we update data of temp with temp->data + temp->rc->data */
  if(temp->rc!=NULL)
  temp->data+=temp->rc->data;
}

/* MAIN FUNCTION */
int main(){
  struct node *root=NULL;
  // root=create(1);
  // root->lc=create(-2);
  // root->rc=create(3);
  // root->lc->lc=create(-4);
  // root->lc->rc=create(5);
  // root->rc->rc=create(6);
    root=create(11);
  root->lc=create(2);
  root->rc=create(-22);
  root->lc->lc=create(4);
  root->lc->rc=create(-5);
  // root->rc->rc=create(6);
  
  /* printing inorder traversal of tree */
  cout<<"Inorder traversal before sum_replacement call: \n";
  inorder_rec(root);
  
  /* calling sum_replacement function */
  sum_replacement(root);
  /* printing inorder traversal of tree */
  cout<<"\nInorder traversal after sum_replacement call: \n";
  inorder_rec(root);
  
  return 0;
}
/*
TIME COMOPLEXITY: O(n)

TESTCASE:
Input::
        1
      /  \
    -2    3
    / \    \
  -4   5    6

Output::
        9
      /   \
     -1    9
    /  \    \
  -4    5    6

Inorder traversal before sum_replacement call: 
-4   -2   5   1   3   6
Inorder traversal after sum_replacement call:
-4   -1   5   9   9   6
*/