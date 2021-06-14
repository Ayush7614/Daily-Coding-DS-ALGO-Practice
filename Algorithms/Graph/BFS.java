// This code is the solution to problem https://leetcode.com/problems/binary-tree-level-order-traversal/

//  Definition for a binary tree node.

  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans=new LinkedList<List<Integer>>() ;
        if(root==null) return ans ;
         Queue<TreeNode> q=new LinkedList() ;
    q.add(root) ;
    while(q.size()>0){
        int cs=q.size() ;
        List<Integer> temp=new LinkedList<>() ;
        // to add all the nodes present on the same level
        while(cs-->0){
       TreeNode cn=q.remove() ;
            temp.add(cn.val) ;
       if(cn.left!=null) q.add(cn.left) ;
       if(cn.right!=null) q.add(cn.right) ;
        }
        ans.add(temp) ;
    }
        return ans ;
    }
}
