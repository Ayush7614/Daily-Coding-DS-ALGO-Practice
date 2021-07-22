//Link to the problem
/*
https://leetcode.com/problems/validate-binary-search-tree/
 */

//According to the problem:
//Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//NOTE:A valid BST is defined as follows:
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

/*Example 1:
Input: root = [2,1,3]
Output: true
//*
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
    bool valid(TreeNode* root,long long int min,long long int max)
    {
        if(root==NULL)//BASE CASE
        return true;
        if(root->val<min||root->val>max)return false;//BASE CASE
        return valid(root->left,min,(long)(root->val)-1)&& valid(root->right,(long)(root->val)+1,max);
    }//traversing its left and right child
    bool isValidBST(TreeNode* root) {
       bool ans=valid(root,INT_MIN,INT_MAX); 
        return ans;
    }
};