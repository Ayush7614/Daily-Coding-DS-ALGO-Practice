// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Given two sorted linked lists consisting of N and M nodes respectively.
// The task is to merge both of the list (in-place) and return head of the merged list.

// Example 1:

// Input:
// N = 4, M = 3 
// valueN[] = {5,10,15,40}
// valueM[] = {2,3,20}
// Output: 2 3 5 10 15 20 40
// Explanation: After merging the two linked
// lists, we have merged list as 2, 3, 5,
// 10, 15, 20, 40.

// Example 2:

// Input:
// N = 2, M = 2
// valueN[] = {1,1}
// valueM[] = {2,4}
// Output:1 1 2 4
// Explanation: After merging the given two
// linked list , we have 1, 1, 2, 4 as
// output.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(1)

// { Driver Code Starts
    import java.util.*;

    class Node
    {
        int data;
        Node next;
        Node(int d) {
            data = d; 
            next = null;
        }
    }
    
    class MergeLists
    {
        Node head;
      /* Function to print linked list */
       public static void printList(Node head)
        {
            
            while (head!= null)
            {
               System.out.print(head.data+" ");
               head = head.next;
            }  
            System.out.println();
        }
     
         /* Driver program to test above functions */
        public static void main(String args[])
        {
           
             
            /* Constructed Linked List is 1->2->3->4->5->6->
               7->8->8->9->null */
             Scanner sc = new Scanner(System.in);
             int t=sc.nextInt();
             
             while(t>0)
             {
                int n1 = sc.nextInt();
                int n2 = sc.nextInt();
                Node head1 = new Node(sc.nextInt());
                Node tail1 = head1;
                for(int i=0; i<n1-1; i++)
                {
                    tail1.next = new Node(sc.nextInt());
                    tail1 = tail1.next;
                }
                Node head2 = new Node(sc.nextInt());
                Node tail2 = head2;
                for(int i=0; i<n2-1; i++)
                {
                    tail2.next = new Node(sc.nextInt());
                    tail2 = tail2.next;
                }
                
                LinkedList obj = new LinkedList();
                Node head = obj.sortedMerge(head1,head2);
                printList(head);
                
                t--;
                
             }
             sc.close();
        }
    }
    // } Driver Code Ends
    
    /*
      Merge two linked lists 
      head pointer input could be NULL as well for empty list
      Node is defined as 
        class Node
        {
            int data;
            Node next;
            Node(int d) {data = d; next = null; }
        }
    */
    
    //Solution class
    class LinkedList
    {
        //Function to merge two sorted linked list.
        Node sortedMerge(Node head1, Node head2) {
            
            //////////method 1 -
            
            if(head1 == null && head2 == null) return null;
            if(head1 == null) return head2;
            if(head2 == null) return head1;
            
            Node temp = new Node(0);
            Node ptr = temp;
            while(head1 != null && head2 != null){
                if(head1.data <= head2.data){
                    ptr.next = new Node(head1.data);
                    ptr = ptr.next;
                    head1 = head1.next;
                }else{
                    ptr.next = new Node(head2.data);
                    ptr = ptr.next;
                    head2 = head2.next;
                }
            }
            
            while(head1 != null){
                ptr.next = new Node(head1.data);
                ptr = ptr.next;
                head1 = head1.next;
            }
            while(head2 != null){
                ptr.next = new Node(head2.data);
                ptr = ptr.next;
                head2 = head2.next;
            }
            return temp.next;
            
            //////////Methode 2 - using recursion
            
            // if(head1 == null) return head2;
            // if(head2 == null) return head1;
            
            // if(head1.data <= head2.data){
            //     head1.next = sortedMerge(head1.next, head2);
            //     return head1;
            // }else{
            //     head2.next = sortedMerge(head1, head2.next);
            //     return head2;
            // }
        } 
    }

// for Method 1 -
// Time Complexity: O(n + m)
// Space Complexity : O(n + m)

// for Method 2 -
// Time Complexity: O(n + m)
// Space Complexity : O(1)