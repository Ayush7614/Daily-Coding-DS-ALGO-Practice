#include <bits/stdc++.h>
using namespace std;
 
struct Node {  //class node
    int data;
    Node* left;
    Node* right;
 
    // constructor of node class
    Node(int val)
    {
        // val is the key or the value that  has to be added to the data part
    
        data = val;
        // As soon as a node is created its left and right child will be initialized to NULL
        left = NULL;
        right = NULL;
    }
};
 
 vector<int> postOrder(Node* root);
 
int main()
{
 
    Node* root = new Node(1);
    // following is the tree after above statement
 
    root->left = new Node(2);
    root->right = new Node(3);
    // 2 and 3 become left and right children of 1
 
    root->left->left = new Node(4);
    // 4 becomes left child of 2
    root->left->right = new Node(5);
    // 5  becomes right child of 2

//				1
//			   / \									
//			  2	  3
//			 / \									
//			4   5
			
//THIS IS THE BINARY TREE FORMED FROM THE GIVEN VALUES
   
   vector<int> ans;
   //calling the function postorder
   ans=postOrder(root);
   //printing the postorder traversal of the given tree
   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";

   return 0;
}
vector<int> postOrder(Node* root) {
    vector<int> op;    //A vector named op is declared
    stack<Node*> S;    //A stack S of type Node* is created

    
    if (root==NULL)     //checks whether the tree is empty
    return op;

    S.push(root);      //the root of the tree is pushed into the stack S
    Node* prev = NULL;

    while (!S.empty()) {   
        //the top element of the stack is stored in current 
        Node* current = S.top();
          
        /* go down the tree in search of a leaf an if found process it
        and pop stack otherwise move down */
        
        if (prev==NULL || prev->left == current || prev->right == current) {
            if (current->left)     
                S.push(current->left);
            else if (current->right)
                S.push(current->right);   
            else {
                S.pop();
                op.push_back(current->data);
            }

            /*go back to the parent node from left and if the parent node has a right child push it into the stack 
            otherwise process the parent and pop stack*/
        } else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                op.push_back(current->data);
            }
            
           //go back to the parent node from right then process the  parent and pop stack 
        } else if (current->right == prev) {
            S.pop();
            op.push_back(current->data);
        }
          //the previous pointer now points to the current node
        prev = current;
    }

    return op;
}
