//  Problem Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

/**
Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

*/

/**
Algorithm

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
          
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


class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right) 
    {   
        
        if (left > right)   //Base Case
            return nullptr;
        int mid = left + (right - left) / 2;  //Getting the middle element
        TreeNode* node = new TreeNode(nums[mid]); //making it a node
        
        //constructing the left subtree recursively and making it left child of root
        node->left = helper(nums, left, mid - 1); 
        
        //constructing the right subtree recursively and making it right child of root
        node->right = helper(nums, mid + 1, right);
        
        return node;
    } 
};
