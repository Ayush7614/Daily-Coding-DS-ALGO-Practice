//Link to problem:
//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

/*Algorithm:
First we will find inorder traversal of BST as it will be in sorted order then we will find mid position of node and keep on 
balancing right and left subtree.

*/

#include <bits/stdc++.h>
using namespace std;

//Tree Node
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

// Function to find Inorder
void inorder(Node *root,vector<Node*>&v){
  
    
    if(!root)
        return;
    
    inorder(root->left,v);
    
    v.push_back(root); 
    inorder(root->right,v);
    
    
}

Node* helper(int start,int end,vector<Node*>&v)
{
    
    
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2; //calculating mid
    
    Node *root=v[mid];
    
    root->left=helper(start,mid-1,v); //balancing left subtree
    root->right=helper(mid+1,end,v); //balancing right subtree
    
    return root;
    
}



Node* buildBalancedTree(Node* root)
{
    vector<Node*>v;
	inorder(root,v);
	
	int start=0;
	int end=v.size();
	
	Node *node=helper(start,end-1,v);
	
	return node;
	
}

// { Driver Code Starts

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) return 0;
  else
  {
      int lDepth = height(node->left);
      int rDepth = height(node->right);
      if (lDepth > rDepth) return(lDepth+1);
      else return(rDepth+1);
  }
return 2;
} 
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin,tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*
Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

*/