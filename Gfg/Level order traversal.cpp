/* A binary tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
//You are required to complete this method
#include<bits/stdc++.h>
void levelOrder(Node* node)
{
  //Your code here
  queue<Node*>q;
  if(node == NULL)
  return;
  q.push(node);
  while(!q.empty())
  {
      Node* t = q.front();
      q.pop();
      cout << t->data <<" ";
      if(t->left != NULL)
      q.push(t->left);
      if(t->right != NULL)
      q.push(t->right);
  }
}
