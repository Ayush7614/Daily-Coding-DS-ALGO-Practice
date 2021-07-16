//Link to problem:
//https://leetcode.com/problems/path-sum-iii/

/*Algorithm:
Keep traversing each node and create a map to store the required value for target sum. 
Count the paths which give target sum and return.

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
    
void solve(Node* root,int k,unordered_map<int,int>m,int &ans,int sum)
{
    if(root==NULL) 
        return;
    sum+=root->data;
          
    if(m.find(sum-k)!=m.end()) //if found in map
        ans+=m[sum-k];
          
    m[sum]++; //storing in map
          
    solve(root->left,k,m,ans,sum); //traversing left subtree
    solve(root->right,k,m,ans,sum); //traversing left subtree
}
    
int pathSum(Node* root, int k) 
{
    unordered_map<int,int>m;
    int ans=0;
    m[0]=1;
    solve(root,k,m,ans,0);
    return ans;
}
    
//{ Driver Code starts
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

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
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        int target;
        cin>>target;

        int ans=pathSum(root,target);
        cout<<ans<<endl;

    
    }
    return 0;
}

/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
*/