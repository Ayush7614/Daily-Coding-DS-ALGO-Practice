//Link to the problem
/*
    https://leetcode.com/problems/binary-tree-level-order-traversal/
 */

//According to the problem:

//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

//AIM: Given the root of a binary tree, return the maximum path sum of any path. 

/*
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
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
    int func(TreeNode* root,int &res)
    {
        if(!root)return 0;//base case
      int l=func(root->left,res);  //traversing left
         int r=func(root->right,res);  //traversing right
      int max_s=max(max(l,r)+root->val,root->val);   
       int max_b=max(max_s,l+r+root->val);    //checking in the same branch
        res=max(res,max_b); //maximum of two
        return max_s;   //returning the maximum path sum
    }
    int maxPathSum(TreeNode* root) {
       int res=INT_MIN;
        func(root,res);
        return res;
    }
};