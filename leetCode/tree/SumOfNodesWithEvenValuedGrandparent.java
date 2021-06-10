package leetCode.tree;

/**
 * Sum of Nodes with Even-Valued Grandparent
 * leetCode Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
 */

public class SumOfNodesWithEvenValuedGrandparent {

    private class TreeNode {
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


    private int getSum(TreeNode grandParent, TreeNode parent)
    {
        if(parent==null)  //Corner Case Handling
            return 0;

        int leftVal = getSum(parent, parent.left);   //We check the sum recursively for right sub Tree
        int rightVal = getSum(parent, parent.right); //We check the sum recursively for right sub Tree
        int currentVal = leftVal + rightVal;   //We add both the results
        if(grandParent!=null && (grandParent.val&1)==0) { //This means that the grand-children should be added to the sum
            if(parent.left!=null)
                currentVal += parent.left.val;  // Add if left grandchildren is not null
            if(parent.right!=null)
                currentVal += parent.right.val; //Add if right grandchildren is not null
        }
        return currentVal;  //Return the value of sum to the calling function
    }

    public int sumEvenGrandparent(TreeNode root)
    {
        if(root==null)
            return 0;

        return getSum(null, root); //We pass the root

    }


}
