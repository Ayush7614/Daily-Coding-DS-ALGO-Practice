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

// Function to print the Right view of the Tree
void rightView(Node *root)
{
    //If root = NULL then return NULL
    if (root == NULL)
        return;

    //Create a vector to store results
    vector<int> ans;

    //Create a Queue for level order traversal and push root in it
    queue<Node *> q;
    q.push(root);

    //Level Order Traversal of the Tree
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == n - 1)
            {
                ans.push_back(temp->data);
            }

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    //Printing the Right view of the Tree
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

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

    cout << "Right view of the given binary tree is : ";
    //calling the function right view
    rightView(root);
    return 0;
}

/* OUTPUT
  
      1
    /  \           
   2    3          
 /  \    \
4    6    5

Right View of the given binary tree is : 1 3 5 
Time Complexity: O(n)

*/