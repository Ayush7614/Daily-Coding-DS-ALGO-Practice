#include<bits/stdc++.h>

using namespace std;
//
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
       // function will print the topView of the binary tree


    void topView(Node *root)
    {
        pair<Node*, int> p;
        queue<pair<Node*, int>> Queue;
        map<int, Node*> mp;
        p = make_pair(root, 0);
        mp[0] = root;
        int idx = 0;
        Queue.push(p);//push node and horizontal distance to queue.
        while(!Queue.empty())
        {
            p = Queue.front();
            Node* ptr = p.first;
            idx = p.second;
            Queue.pop();
            if(ptr->left)
            {
                --idx;
                if(!mp[idx])
                    mp[idx] = ptr->left;
                Queue.push(make_pair(ptr->left, idx));
            }
            idx = p.second;
            if(ptr->right)
            {
                ++idx;
                if(!mp[idx])
                    mp[idx] = ptr->right;
                Queue.push(make_pair(ptr->right, idx));
            }
        }
        for(const auto &i : mp)
            cout<<i.second->data<<' ';
        cout<<'\n';
    }
}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
