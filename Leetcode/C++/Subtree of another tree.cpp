//Link to the problem
/*
   https://leetcode.com/problems/subtree-of-another-tree/
 */

//According to the problem:
//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

//NOTE:A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

/*
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
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
      bool isSame(TreeNode *r1,TreeNode *r2){
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2 )
            return false;
        if(r1->val!=r2->val)
            return false;
        return (isSame(r1->left,r2->left) && isSame(r1->right,r2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
          if(!root && !subRoot)//base case 1
            return true;
        if(!root && subRoot)//Base case 2
            return false;
        if(root && !subRoot)//Base case 3
            return true;
        int v1=root->val,v2=subRoot->val;
        if(v1==v2)
            return ((isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)) );
        else{
            return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        }
    }
};