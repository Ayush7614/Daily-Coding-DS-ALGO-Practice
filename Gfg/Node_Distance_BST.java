public class Node_Distance_BST{

   public static class Node{
        int key;
        Node left,right;
        public Node(int key){
            this.key = key;
        }
    }
    static Node Least_Common_ancestor(Node root,int num1,int num2){
        if(root == null)
            return root;
        if(root.key == num1 || root.key == num2)
            return root;

        Node left = Least_Common_ancestor(root.left, num1, num2);
        Node right = Least_Common_ancestor(root.right, num1, num2);

        if(left != null && right != null)
            return root;
        if(left == null && right == null)
            return null;
        if(left!=null)
            return Least_Common_ancestor(root.left, num1, num2);
        else
           return Least_Common_ancestor(root.right, num1, num2);
    }

    public static int findLevel(Node root,int num ,int level){
        if(root == null)
            return -1;
        if(root.key == num)
            return level;
        int leftLevel = findLevel(root.left, num, level+1);
        if(leftLevel == -1)
            return findLevel(root.right, num, level + 1);
        return leftLevel;
    }
    
    public static int findDistance(Node root, int num1, int num2) {
        Node lca = Least_Common_ancestor(root, num1, num2);

        int d1 = findLevel(lca, num1, 0);
        int d2 = findLevel(lca, num2, 0);

        return d1 + d2;
    }

    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.right.left.right = new Node(8);
        System.out.println("Dist(4, 5) = " + findDistance(root, 4, 5));

        System.out.println("Dist(4, 6) = " + findDistance(root, 4, 6));

        System.out.println("Dist(3, 4) = " + findDistance(root, 3, 4));

        System.out.println("Dist(2, 4) = " + findDistance(root, 2, 4));

        System.out.println("Dist(8, 5) = " + findDistance(root, 8, 5));

    }
}