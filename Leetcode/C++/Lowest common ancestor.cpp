//Link of question:

//Given:Given a binary search tree (BST).

//Note:According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

//AIM:find the lowest common ancestor (LCA) of two given nodes in the BST.

//Example:

/*Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8

Output: 6

Explanation: The LCA of nodes 2 and 8 is 6.4*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL)
            //BST is a tree where all its left child are smaller than its root and right are greater than it using the fact!
        {
            if(root->val<p->val&&root->val<q->val)
                //val greator traversing right
                root=root->right;
            
            else if(root->val>p->val&&root->val>q->val)
                //val small traversing left
                root=root->left;
            
            else break;
            
        }
        return root;//Returning LCA
    }
};