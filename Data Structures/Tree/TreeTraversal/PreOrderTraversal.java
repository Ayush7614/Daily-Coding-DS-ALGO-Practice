package Tree.TreeTraversal;

/**
 * Recursive Binary Tree PreOder Traversal Code
 */


class PreOrderTraversal {

    private class TreeNode {
        int data;
        TreeNode left, right;
        TreeNode(int item)    {
            data = item;
            left = right = null;
        }
    }

    void printPreOrder(TreeNode node) //pass root node here
    {
        if(node==null)
            return;

        System.out.println(node.data+" ");
        printPreOrder(node.left); //Recursively call for left subtree
        printPreOrder(node.right); //Recursively call for right subtree
    }

}