package Tree.TreeTraversal;

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

        printPostOrder(node.left);
        printPostOrder(node.right);
        System.out.println(node.data+" ");
    }

}
