#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
// function to print the zigzag traversal
void zizag_traversal(struct Node* root)
{
    if (!root)
        return;
 
    stack<Node*> curr;
    stack<Node*> nextlevel;
 
    curr.push(root);
 
    // check if stack is empty  
    bool pre = true;
    while (!curr.empty()) {
 
        // pop out of stack
        struct Node* temp = curr.top();
        curr.pop();
 
          if (temp) {
            cout << temp->data << " ";
 
            // store data according to current order.
            
            if (pre) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (curr.empty()) {
            pre = !pre;
            swap(curr, nextlevel);
        }
    }
}
 
int main()
{
    // creating a tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    zizag_traversal(root);
 
    return 0;
}

/*
Time Complexity: O(n) 
Space Complexity: O(n)
*/
