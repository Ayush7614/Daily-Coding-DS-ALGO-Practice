//Link to the problem
/*
https://leetcode.com/problems/deepest-leaves-sum/                                     
*/

//According to the problem:

//Given the root of a binary tree

//AIM:  Return the sum of values of its deepest leaves.

/*Sample Example :
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
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
    int sum=0;  //global variable holding sum of all deepest leaves
   
    //Function to find height
    int height(TreeNode* root)
    {
          if(root==NULL)
        {
            return -1;
        }
       int lh=height(root->left);//checking for left child
        int rh=height(root->right);//checking for right child
        return max(lh,rh)+1;//height of tree
    }

    void cal(TreeNode* root,int k,int h)
    {
          
        if(root->left==NULL&&root->right==NULL&&h==k)//root now has no children and h turns equal to height 
            sum+=root->val;///deepest node found
        if(root->left)//traversing left
            cal(root->left,k,h+1);
        if(root->right)//traversing right
            cal(root->right,k,h+1);
    }

   
    int deepestLeavesSum(TreeNode* root) {
    int k=height(root);//calling height()
    cal(root,k,0);//calling cal()
        return sum;//returning required ans
    }
};