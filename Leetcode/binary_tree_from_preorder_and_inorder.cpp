//--Construct Binary Tree from inorder and preorder traversals--//

/* 
  Problem link is:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /* 
        Inorder to make recursive calls to build a tree using preorder and inorder 
        traversal, we have a made a seperate function ans() which will return the 
        root node of tree and we will call it recursively to build a tree.
        */
        return ans(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    /* 
    ans() function takes arguments as preorder, inorder, pi, pe, ii, ie
    pi- denotes the starting index of preorder array from where we have to add nodes to tree
    pe- denotes the last index of preorder , till here we have to add nodes for a given sub-tree
    ii- denotes the starting index of inorder array from where we have to search position of given node
        and then make the following subtrees of given node.
    ie- denotes the last index of inorder , till here we have to search a node.
    */


    TreeNode* ans(vector<int>& preorder, vector<int>& inorder,int pi, int pe,int ii, int ie)
    {  
        if(pi>pe) // if starting index of preorder becomes more than ending index, it means 
            return NULL; // all nodes for a certain sub-tree has been added and hence returned 
                        // null pointer
        TreeNode *temp = new TreeNode(preorder[pi]);// makes a new node of a starting index of preorder 

        int position;// this will store the position of the given node in inorder array

        for(int i=ii;i<ie;i++) // this loop finds position of new node in inorder array
        {
            if(temp->val==inorder[i])
            {
                position=i;
                break;
            }
        }
        
        // Recursive calls to build left-subtree and right sub-tree of above node

        /* 
         Now, to build left-subtree, we increment pi by 1, and pe(only to build left sub-tree of given node) 
         will be pi+position-ii, and in inorder array, left subtree nodes will between ii and position-1
        */
        temp->left=ans(preorder,inorder,pi+1,pi+position-ii,ii,position-1);
        
        /* 
        Now, to build right-subtree, we increment pi by position-ii+1(only to build right sub-tree of given node)
        and pe will be as same, and in inorder array, right subtree nodes will between position+1 and ie
        */
        temp->right=ans(preorder,inorder,pi+position-ii+1,pe,position+1,ie);
        
        return temp; // return the root node
    }
    
};