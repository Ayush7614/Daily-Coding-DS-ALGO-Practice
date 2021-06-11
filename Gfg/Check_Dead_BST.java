public class Check_Dead_BST{
    class Node{
        int data;
        Node left,right;
         public Node(int item){
             data = item;
             left=right=null;
         }
    }

    Node root;

    Node insertNode(int data,Node root){
        if(root == null){
            root = new Node(data);
            return root;
        }
        
        if(data < root.data)
            root.left = insertNode(data,root.left);
        else
            root.right = insertNode(data, root.right);

        return root;
    }

    void insert(int data){
        root = insertNode(data,root);
    }

    boolean checkDeadBST(Node root,int min,int max){
        if(root == null)
            return false;

        if(min == max)
            return true;

        return checkDeadBST(root.left,min,root.data-1) || checkDeadBST(root.right,root.data+1,max);
    }
    public static void main(String[] args) {
        Check_Dead_BST BSTtree = new Check_Dead_BST();

        BSTtree.insert(8);
        BSTtree.insert(5);
        BSTtree.insert(2);
        BSTtree.insert(3);
        BSTtree.insert(7);
        BSTtree.insert(11);
        BSTtree.insert(4);

        if (BSTtree.checkDeadBST(BSTtree.root, 1, Integer.MAX_VALUE) == true)
            System.out.println("Yes ");
        else
            System.out.println("No ");
    }
}