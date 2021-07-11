//Link to problem :
// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*Algorithm:

We will keep traversing each node of tree and calculating the longest path and sum simultaneously.
At last will return the largest sum of longest path.

*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


vector<int>helper(Node *root)
{
        if(root==NULL)
            return {0,0};
            
        vector<int>a=helper(root->left);
        vector<int>b=helper(root->right);
        
        // comparing longest path of left and right subtree
        if(a[0]>b[0])  // left subtree has longest path
            return {a[0]+1,a[1]+root->data};
        
        else
        {
            if(a[0]<b[0]) // right subtree has longest path
                return {b[0]+1,b[1]+root->data};
            else
                 return {a[0]+1,max(a[1],b[1])+root->data}; // both subtree having same nodes hence taking the max sum
            
        }
        
}
    
int sumOfLongRootToLeafPath(Node *root)
{
    vector<int>ans=helper(root); // helper() function called
        
    return ans[1];
        
}

// { Driver Code Starts

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution
{
public:

    
};


int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
   
        int res = sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends

/*
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

Output: 11



*/