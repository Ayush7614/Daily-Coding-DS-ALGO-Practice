//Link to problem :
// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

/*Algorithm: We will convert the traversed nodes in form a string and store in it map. If in map the frequency of any string 
becomes 2 or more we will return true.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};


unordered_map<string,int>m;

//helper function
string help(Node *root)
{
    if(root==NULL)
        return "#"; // Base case
      string s="";
    if(root->right==NULL && root->left==NULL) // For leaf node
    {
        s=to_string(root->data);
        return s;
    }
    
    s=s+to_string(root->data);
    s=s+help(root->left);
    s=s+help(root->right);
     
     m[s]++; // storing in map
     return s;
    
}

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/

bool dupSub(Node *root)
{
    m.clear();
    help(root);
    
    for(auto x:m)
        if(x.second>=2) // checking in map
            return true;
            
            
    return false;   
}


// { Driver Code Starts
struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

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



int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		//Solution ob;
		cout << dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends

/*Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

*/