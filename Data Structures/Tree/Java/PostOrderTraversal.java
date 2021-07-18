package Tree.TreeTraversal;

/**
 * Recursive Binary Tree PostOder Traversal Code
 */

public class PostOrderTraversal {

    private class TreeNode {
        int data;
        TreeNode left, right;
        TreeNode(int item)    {
            data = item;
            left = right = null;
        }
    }

    void printPostOrder(TreeNode node) //pass root node here
    {
        if(node==null)
            return;

        printPostOrder(node.left); //Recursively call for left subtree
        printPostOrder(node.right); //Recursively call for right subtree
        System.out.println(node.data+" ");
    }

}
