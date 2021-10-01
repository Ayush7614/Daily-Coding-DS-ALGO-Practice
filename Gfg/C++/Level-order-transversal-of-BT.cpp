/*
Level order traversal 
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N
*/
// code
class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            ans.push_back(t->data);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            q.pop();
        }
        return ans;
    }
};