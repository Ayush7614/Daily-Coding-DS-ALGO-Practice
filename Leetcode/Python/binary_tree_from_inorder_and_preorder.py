# 105. Construct Binary Tree from inorder and preorder traversals

#Problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#Algorithm:
"""
1. Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
2. Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
3. Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
     if the range is empty, return null;
     initialize the root with preorder[preorderIndex] and then increment preorderIndex;
     recursively use the left and right portions of inorder to construct the left and right subtrees.
4. Simply call the recursion function with the entire range of inorder.
"""

#Solution:

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def array_to_tree(left, right):
            nonlocal preorder_index
            # if there are no elements to construct the tree
            if left > right: 
                return None

            # select the preorder_index element as the root and increment it
            root_value = preorder[preorder_index]
            root = TreeNode(root_value)
            preorder_index += 1

            # build left and right subtree
            # excluding inorder_index_map[root_value] element because it's the root
            root.left = array_to_tree(left, inorder_index_map[root_value] - 1)
            root.right = array_to_tree(inorder_index_map[root_value] + 1, right)

            return root

        preorder_index = 0

        # build a hashmap to store value -> its index relations
        inorder_index_map = {}
        for index, value in enumerate(inorder):
            inorder_index_map[value] = index

        return array_to_tree(0, len(preorder) - 1)

#Complexity analysis
#   Time complexity : O(N)
#   Space complexity : O(N)