//POST ORDER TRAVERSAL 
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

//POSTORDER TRAVERSAL
void postOrder(node* root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"\n Post order transversal: ";
    postOrder(root);
}