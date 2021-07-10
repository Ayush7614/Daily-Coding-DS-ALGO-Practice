/* C++ Program to find LCA of two nodes p and q  of Binary Tree */
#include <iostream>

using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that p and q are present in Binary Tree
struct Node *findLCA(struct Node* root, int p, int q)
{
	// Base case
	if (root == NULL) return NULL;

	// If either p or q matches with root's key, report
	// the presence by returning root (Note that if a key is
	// ancestor of other, then the ancestor key becomes LCA
	if (root->key == p || root->key == q)
		return root;

	// Look for keys in left and right subtrees
	Node *left_lca = findLCA(root->left, p, q);
	Node *right_lca = findLCA(root->right, p, q);

	// If both of the above calls return Non-NULL, then one key
	// is present in once subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca) return root;

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL)? left_lca: right_lca;
}

// Driver program to test above functions
int main()
{
	
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
	return 0;
}

// OUTPUT:
LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(3, 4) = 1
LCA(2, 4) = 2


//Time Complexity: The time complexity  is O(n) . 



