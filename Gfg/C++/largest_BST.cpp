//Link to problem:
// https://practice.geeksforgeeks.org/problems/largest-bst/1

/* Algorithm:
For each node we will store {BST(1,0),Size so far,min data, max data}. If the current node of data is greater than 
largest data from left subtree and is smaller than smallest data from right subtree and from both subtree(right and left) 
the value of BST is 1 means from that node we can get BST, hence keep on updating {BST(1,0),Size so far,min data, max data}.
At last size so far will be the answer.

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


vector<int>helper(Node *root)
{
    if(root==NULL)
        return {1,0,INT_MAX,INT_MIN};
    if(root->left==NULL && root->right==NULL) // For leaf node
        return {1,1,root->data,root->data};
        
    vector<int>a=helper(root->left);
    vector<int>b=helper(root->right);
    
    if(a[0]==1 && b[0]==1) // BST is possible
    {
        if(a[3]<root->data && root->data<b[2]) //Checking BST conditions
        {
            int l=a[2];
            int r=b[3];
            
            if(l==INT_MAX)
                l=root->data;
            if(r==INT_MIN)
                r=root->data;
                
            return {1,a[1]+b[1]+1,l,r};
        }
    }
    
    return {0,max(a[1],b[1]),0,0};
    
    
    
}

int largestBst(Node *root)
{
    vector<int>ans=helper(root);
    
    return ans[1];
}


//{ Driver Code Starts
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

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

// } Driver Code Ends

/*
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 

Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8

*/
