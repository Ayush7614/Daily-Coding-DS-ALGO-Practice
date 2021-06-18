package Tree.TreeTraversal;

/**
 * Recursive Binary Tree InOder Traversal Code
 */

class InOrderTraversal {

    private class TreeNode {
        int data;
        TreeNode left, right;
        TreeNode(int item)    {
            data = item;
            left = right = null;
        }
    }

    void printInOrder(TreeNode node) //Pass the root node
    {
        if(node==null)
            return;

        printInOrder(node.left); //Recursively call for left subtree
        System.out.println(node.data+" ");
        printInOrder(node.right); //Recursively call for right subtree
    }

}
