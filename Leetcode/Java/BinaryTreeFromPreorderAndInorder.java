/**
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of 
 * a binary tree and inorder is the inorder traversal of the same tree, construct and return 
 * the binary tree.
 */
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
import java.util.*;
class BinaryTreeFromPreorderAndInorder
{
    int pr=0;
    //Function to find index of value in inorder[]
    public int search(int inorder[],int x)
    {
        for(int i=0;i<inorder.length;i++)
            if(x==inorder[i])
                return i;
        return -1;
    }
    //Function to build binary Tree
    public TreeNode buildTree(int[] preorder, int[] inorder)
    {
        if(inorder.length==0)
            return null;
        //Pick current node from preorder traversal using pr(increament index)
        TreeNode tNode=new TreeNode(preorder[pr++]);
        //If node has no children
        if(inorder.length==1)
            return tNode;
        //find the index of this node in inorder traversal
        int id=search(inorder,tNode.val);
        int inL[]=new int[id];
        int inR[]=new int[inorder.length-1-id];int k=0;
        // Storing left and right elements of node in different array
        for(int i=0;i<id;i++)
            inL[i]=inorder[i];
        for(int i=id+1;i<inorder.length;i++)
            inR[k++]=inorder[i];
      //using index in inorder traversal ,construct left and right subtrees
        tNode.left=buildTree(preorder,inL);
        tNode.right=buildTree(preorder,inR);
        return tNode;
    }
    /* function to print level order traversal of tree*/
    void printLevelOrder(TreeNode root)
    {
        int h = height(root);
        int i;
        for (i=1; i<=h; i++)
            printCurrentLevel(root, i);
    }

    /* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
    int height(TreeNode root)
    {
        if (root == null)
           return 0;
        else
        {
            /* compute  height of each subtree */
            int lheight = height(root.left);
            int rheight = height(root.right);

            /* use the larger one */
            if (lheight > rheight)
                return(lheight+1);
            else return(rheight+1);
        }
    }

    /* Print nodes at the current level */
    void printCurrentLevel (TreeNode root ,int level)
    {
        if (root == null)
        {
        	System.out.print("null ");
        	return;
        }
        if (level == 1)
            System.out.print(root.val + " ");
        else if (level > 1)
        {
            printCurrentLevel(root.left, level-1);
            printCurrentLevel(root.right, level-1);
        }
    }

    public static void main(String args[])
    {
    	Scanner sc=new Scanner(System.in);
    	BinaryTreeFromPreorderAndInorder t=new BinaryTreeFromPreorderAndInorder();
    	System.out.print("Give no. of variables of binary tree");
    	int n=sc.nextInt();
    	int p[]= new int[n];
    	int in[]= new int[n];
    	System.out.println("Write preorder");
    	for(int i=0;i<n;i++)
    		p[i]=sc.nextInt();
    	System.out.println("Write inorder");
    	for(int i=0;i<n;i++)
    		in[i]=sc.nextInt();
    	TreeNode r=t.buildTree(p,in);
    	System.out.println("Resultant Binary Tree");
    	t.printLevelOrder(r);
    }
} 
/*
 * Test Case
 * Give no. of variables of binary tree
 * 5
 * Write preorder
 * 3 9 20 15 7
 * Write inorder
 * 9 3 15 20 7
 * Resultant Binary Tree
 * 3 9 20 null null 15 7
 */
