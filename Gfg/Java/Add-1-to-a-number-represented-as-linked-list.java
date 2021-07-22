// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

// A number N is represented in Linked List such that each digit corresponds to a node in linked list.
// You need to add 1 to it.

// Input:
// LinkedList: 4->5->6
// Output: 457

// Input:
// LinkedList: 1->9->9->9
// Output: 2000

// { Driver Code Starts
    import java.util.*;
    /*
    class Node{
        int data;
        Node next;
        
        Node(int x){
            data = x;
            next = null;
        }
    } 
    */
    class add
    {
        public static void printList(Node node) 
        { 
            while (node != null)
            { 
                System.out.print(node.data);
                node = node.next; 
            }
            System.out.println();
        } 
        public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s = sc.next();
                    Node head = new Node( s.charAt(0) - '0' );
                    Node tail = head;
                    for(int i=1; i<s.length(); i++)
                    {
                        tail.next = new Node( s.charAt(i) - '0' );
                        tail = tail.next;
                    }
                    add1toll obj = new add1toll();
                    head = obj.addOne(head);
                    printList(head); 
                }
                sc.close();
        }
    }// } Driver Code Ends
    
    
    //Solution class
    class add1toll
    {
        Node addOne(Node head) 
        {
            //first reverse the list.
            head = reverse(head);
            //second perform the addition.
            head = add1(head);
            //return the list after reversing it again to get your desiered list.
            return reverse(head);
        }
        static Node add1(Node head){
            Node temp = null;
            Node result = head;
            int carry = 1, sum = 0;
            while(head != null){
                sum = carry + head.data;
                carry = (sum >= 10) ? 1 : 0;
                sum = sum % 10;
                head.data = sum;
                temp = head;
                head = head.next;
            }
            //if there is something left in the carry
            //add another node and put it in that
            if(carry > 0)
                temp.next = new Node(carry);
            return result;
        }
        static Node reverse(Node head){
            Node current = head;
            Node prev = null;
            Node next = null;
            while(current != null){
                next = current.next;
                current.next = prev;
                prev = current;
                current = next;
            }
            head = prev;
            return head;
        }
        //Time complexity - O(N), as we have to reverse the linked list which takes O(N) time complexity.
        //                        and then we have to traverse throught the LL
        //                        in order to add 1 which also takes O(N) time.
        //                        so the time complexity will be approx. O(N).
        //Space complexity - O(1), we are using only constant space.
    }