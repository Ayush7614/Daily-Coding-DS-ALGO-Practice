#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to print the bottom view of the Tree
void bottomView(Node *root)
{
    //If root = NULL then return NULL
    if (root == NULL)
        return;

    //Create a Queue with a pair to store the position of the node in level order traversal
    queue<pair<Node *, int>> q;
    //Create a map to store the nodes in it according to their position
    map<int, int> m;
    //Pushed the root in the queue & marked its position as 0
    q.push({root, 0});

    //Level Order Traversal of the Tree
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int d = q.front().second;
        q.pop();

        //Storing the node in the map according to its position
        m[d] = temp->data;

        if (temp->left != NULL)
            q.push({temp->left, d - 1});

        if (temp->right != NULL)
            q.push({temp->right, d + 1});
    }

    //Printing the bottom view of the Tree
    for (auto it = m.begin(); it != m.end(); it++)
        cout << (it->second) << " ";

    return;
}

//Main function
int main()
{
    /*Creating the Tree 
             1
           /  \
          2    3
        /  \    \
       4    6    5  */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(5);

    cout << "Bottom view of the given binary tree is : ";
    //calling the function bottom view
    bottomView(root);
    return 0;
}

/* OUTPUT
  
      1
    /  \           
   2    3          
 /  \    \
4    6    5

Bottom View of the given binary tree is : 4 2 6 3 5

Time Complexity: O(n)

*/