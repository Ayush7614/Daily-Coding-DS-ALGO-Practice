//Link to problem:
//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

/*Algorithm:
We will use two stacks for two BST tree. If anyone of tree is empty then we will find the inorder of that tree and return it as answer.
If both are not empty then we will push it in separate stack and keep on poping elements and keeping the min value in answer vector.

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

//Calculating inorder of tree
void inorder(Node *root, vector<int> &v)
{
    
    if(root==NULL)
        return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

//function to get min value node
Node *minValueNode(Node *node)
{
    Node *curr=node;

    while(curr->left!=NULL)
        curr=curr->left;

    return curr;
}
    
//function merge BST in sorted order
vector<int> merge(Node *root1,Node *root2)
{
    //using two stacks
    stack<Node*> s1;
    stack<Node*> s2;
        
    Node *c1=root1;
    Node *c2=root2;
    
    vector<int>ans;
        
    //if first BST is empty then output is inorder traversal of second BST.
    if(root1==NULL)
    {
        inorder(root2, ans);
        return ans;
    }

    //if second BST is empty then output is inorder traversal of first BST.
    if(root2==NULL)
    {
        inorder(root1, ans);
        return ans;
    }
        
        
    while(c1!=NULL || !s1.empty() || c2!=NULL || !s2.empty())
    {
    
        if(c1!=NULL or c2!=NULL) //storing data in s1 and s2 stack
        {
            
            if(c1!=NULL)
            {
                s1.push(c1);
                c1 = c1->left;
            }
            if(c2!=NULL)
            {
                s2.push(c2);
                c2 = c2->left;
            }
        }
            
        else 
        {
            //if either of the stacks is empty 
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    c2=s2.top();
                    s2.pop();
                    c2->left= NULL;
                    inorder(c2, ans);
                }
                return ans;

            }

            if(s2.empty())
            {
                while(!s1.empty())
                {
                    c1  = s1.top();
                    s1.pop();
                    c1->left = NULL;
                    inorder(c1, ans);
                }

                return ans;
            }

            //poping one element from both stacks and comparing
            c1 = s1.top();
            c2  = s2.top();
            s1.pop();
            s2.pop();
                
             
            if(c1->data < c2->data)
            {
                ans.push_back(c1->data);
                c1 = c1->right;
                s2.push(c2);
                c2 = NULL;
            }
                
            else
            {
                ans.push_back(c2->data);
                c2 = c2->right;
                s1.push(c1);
                c1 = NULL;
            }
        }
    }
        
        return ans;
}


// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}


int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
    
       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       
   }
   return 0;
}  // } Driver Code Ends

/*
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
    
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

*/