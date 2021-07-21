
/*

Let’s say we want to search for the number, what we’ll do is we’ll start at the root, and then we will compare 
the value to be searched with the value of the root if it’s equal we are done with the search if it’s lesser 
we know that we need to go to the left subtree because in a binary search tree all the elements in the left 
subtree are lesser and all the elements in the right subtree are greater. 

*/

#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	
	node(int x){				
		data = x;
		left = nullptr;
		right = nullptr;
	}

};

node* bst(node* root, int data){

	// making new node
	if(root == nullptr){				
		root = new node(data);
		return root;
	}

	else if(data < root->data){
		root->left = bst(root->left,data);
	}
	else{
		root->right = bst(root->right,data);
	}

	return root;
}
node* cbst(){

	// this is a  root node
	int data;				
	cin >> data;

	node* root = nullptr;

	while(data!= -1){ 
		root = bst(root, data);
		cin >> data;
	}

	return root;
}
//Searching an element in the 
//binary search tree is basically this traversal in which at each step we will go either towards left or right 
//and hence in at each step we discard one of the sub-trees.

bool search(node* root, int key){

	if(root == nullptr)
		return false;

	if(root->data == key)
		return true;

	else if(root->data > key){
		search(root->left, key);
	}
	else{
		search(root->right, key);
	}

	
}

int main(){

	node* root = cbst();
	int ele;
	cin >> ele;
    cout << boolalpha << search(root, ele);
	return 0;
}




	Test Case :

	Input : 1 2 3 4 5 6 -1
	4

	Outout : true


 */
