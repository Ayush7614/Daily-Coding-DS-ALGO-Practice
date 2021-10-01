/*
Preorder Traversal
Preorder traversal fashion : 
(N) Process n itself.
(L) Recursively traverse its left subtree. When this step is finished, we are back at n again.
(R) Recursively traverse its right subtree. When this step is finished, we are back at n again
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int key)
{
    node* tmp = new node();
    tmp->data = key;
    tmp->left = tmp->right = nullptr;
 
    return tmp;
}

//INSERTION 
node* insert(node* root, int l_data){
    if(root == nullptr){
        return newNode(l_data);
    }
    if(l_data <= root->data){
        root->left = insert(root->left, l_data);
    }else{
        root->right = insert(root->right, l_data);
    }
    return root;
}
//PREORDER TRAVERSAL
void preOrder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"\n Pre order transversal: ";
    preOrder(root);
}