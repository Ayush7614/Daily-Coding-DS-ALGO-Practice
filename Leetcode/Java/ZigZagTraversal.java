// solution to the question-https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
//    bfs solution with the help of two stacks
    public List<List<Integer>> zigzagLevelOrder(TreeNode node) {
        List<List<Integer>> ans=new ArrayList<>() ;
        if(node==null) return ans ;
        Stack < TreeNode > p = new Stack();
        Stack < TreeNode > c = new Stack();
        p.add(node);
        List<Integer> temp=new LinkedList() ;
        boolean flag = true;
        while (p.size() > 0) {
            TreeNode cn = p.pop();
            temp.add(cn.val) ;
            if (flag) {
               if(cn.left!=null) c.push(cn.left) ;
               if(cn.right!=null) c.push(cn.right) ;
            } 
            else {
                if(cn.right!=null) c.push(cn.right) ;
                if(cn.left!=null) c.push(cn.left) ;
                }
                
                if (p.size() == 0) {
                    ans.add(temp) ;
                    temp=new LinkedList() ;
                    p = c;
                    c = new Stack < TreeNode > ();
                    flag=!flag ;
                }
            }
        return ans ;
    }
}