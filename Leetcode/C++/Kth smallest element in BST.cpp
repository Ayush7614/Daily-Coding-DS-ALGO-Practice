//Link to the problem
/*
  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 */

//According to the problem:
//Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

 

/*Input: root = [3,1,4,null,2], k = 1
Output:1*/
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
 *//**
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
    int small(TreeNode* root, int &k)
    {
        int ans;
        if(root==NULL)//base case
            return 0;
        int left=small(root->left,k);//     traversing left                                
        if(left)    //return left
            return left;
        k--;//approaching to the kth element thus decrementing
        if(k==0)//found val
            return root->val;//return
      int right=small(root->right,k);//traverse right
          return right;  
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=small(root,k);//calling small()
        return ans;
    }
};