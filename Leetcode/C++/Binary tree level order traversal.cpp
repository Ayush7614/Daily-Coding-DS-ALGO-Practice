//Link to the problem
/*
    https://leetcode.com/problems/binary-tree-level-order-traversal/
 */

//According to the problem:

//Given the root of a binary tree. 
//AIM: Rreturn the level order traversal of its nodes' values. (i.e., from left to right, level by level).

/*Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;//need a queue to make a BFS traversal
        q.push(root);//pushing the root
        q.push(NULL);//pushing a null since level 1 is inputed already
        
        vector<vector<int>>vv;//2d vector to store final order
        vector<int>v;//temporary vector
         if(root==NULL)//base case
            return vv  ;
        while(q.size()>1)//means elements are present.
        {
            TreeNode* temp=q.front();//first element in the queue
         q.pop();//popping and if it is not null pushing its children
            if(temp==NULL)
            {
                  vv.push_back(v);//pushing the enqueued nodes
                while(!v.empty())//removing null
                v.pop_back();
                q.push(NULL);//pushing another creating a marker of new level added
                continue;
            }
         v.push_back(temp->val);//pushing the q.front()
         if(temp->left!=NULL)//checking its children
             q.push(temp->left);
          if(temp->right!=NULL)
             q.push(temp->right);
         
        }
        vv.push_back(v);//pushing the enqueued nodes
        return vv;//returing the level order traversal
    }
};