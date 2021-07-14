//Link to problem:
//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

/*Algorithm:
We will inorder traverse the tree as BST inorder will be in sorted order and keep the count. When the count will become equal to k
we will return the node value.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void helper(Node* root,int k,int &i,int &ans)
{
    if(!root)
        return;

    helper(root->left,k,i,ans);
    if(i==k) //index becomes equal to k
    {
        ans=root->data;
        i++;
        return ;
            
    }
    else
        i++;
    helper(root->right,k,i,ans);
        
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int k)
{
        
    int i=1,ans=-1;
       
    helper(root,k,i,ans); //helper function
        
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
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);

       cout <<KthSmallestElement(root, k) << endl;
      
   }
   return 0;
}  // } Driver Code Ends

/*
Input:
        2
      /  \
     1    6
K = 3
Output: 6
*/