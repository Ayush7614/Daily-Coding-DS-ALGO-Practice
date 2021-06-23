#include <bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data;           // data of the node
    Node *left, *right; // left and right references

    // Constructor of tree node
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to print the bottom view.
void bottomView(Node *root)
{

    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int d = q.front().second;
        q.pop();

        m[d] = temp->data;

        if (temp->left != NULL)
            q.push({temp->left, d - 1});

        if (temp->right != NULL)
            q.push({temp->right, d + 1});
    }

    for (auto it = m.begin(); it != m.end(); it++)
        cout << (it->second) << " ";

    return;
}

//Main function
int main()
{
    /*Creating the Tree 
            1
           /\
          2  3
         /    \
        4      5  */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Bottom view of the given binary tree is :";
    //calling the function bottom view
    bottomView(root);
    return 0;
}