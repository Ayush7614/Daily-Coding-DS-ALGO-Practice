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
class Solution
{
    int pr=0;
    public int search(int inorder[],int x)
    {
        for(int i=0;i<inorder.length;i++)
            if(x==inorder[i])
                return i;
        return -1;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder)
    {
        if(inorder.length==0)
            return null;
        TreeNode tNode=new TreeNode(preorder[pr++]);
        if(inorder.length==1)
            return tNode;
        int id=search(inorder,tNode.val);
        int inL[]=new int[id];
        int inR[]=new int[inorder.length-1-id];int k=0;
        for(int i=0;i<id;i++)
            inL[i]=inorder[i];
        for(int i=id+1;i<inorder.length;i++)
            inR[k++]=inorder[i];
        tNode.left=buildTree(preorder,inL);
        tNode.right=buildTree(preorder,inR);
        return tNode;
    }
}