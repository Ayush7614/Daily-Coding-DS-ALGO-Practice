//Given an unsorted linked list of N nodes.
//The task is to remove duplicate elements from this unsorted Linked List.
//When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

//Example test cases :-

// Input:
// N = 4
// value[] = {5,2,2,4}
// Output: 5 2 4
// Explanation:Given linked list elements are
// 5->2->2->4, in which 2 is repeated only.
// So, we will delete the extra repeated
// elements 2 from the linked list and the
// resultant linked list will contain 5->2->4

// Input:
// N = 5
// value[] = {2,2,2,2,2}
// Output: 2
// Explanation:Given linked list elements are
// 2->2->2->2->2, in which 2 is repeated. So,
// we will delete the extra repeated elements
// 2 from the linked list and the resultant
// linked list will contain only 2.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

import java.util.HashSet;
 
public class Remove_Duplicate_Elements_from_Unsorted_LL
{
    static class node
    {
        int val;
        node next;
 
        public node(int val)
        {
            this.val = val;
        }
    }
     
    /* Function to remove duplicates from a
       unsorted linked list */
    static void removeDuplicate(node head)
    {
        // Hash to store seen values
        HashSet<Integer> hs = new HashSet<>();
     
        /* Pick elements one by one */
        node current = head;
        node prev = null;
        while (current != null)
        {
            int curval = current.val;
             
             // If current value is seen before
             // skip the value and remove it from the list.
             // else add the value to the hashset and continue to iterate.
            if (hs.contains(curval)) {
                prev.next = current.next;
            } else {
                hs.add(curval);
                prev = current;
            }
            current = current.next;
        }
 
    }
     
    /* Function to print nodes in a given linked list */
    static void printList(node head)
    {
        while (head != null)
        {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
 
    public static void main(String[] args)
    {
        /* The constructed linked list is:
         10->12->11->11->12->11->10*/
        node start = new node(10);
        start.next = new node(12);
        start.next.next = new node(11);
        start.next.next.next = new node(11);
        start.next.next.next.next = new node(12);
        start.next.next.next.next.next = new node(11);
        start.next.next.next.next.next.next = new node(10);
 
        System.out.println("Linked list before removing duplicates :");
        printList(start);
 
        removeDuplicate(start);
 
        System.out.println("\nLinked list after removing duplicates :");
        printList(start);
    }
}

//Time Complexity : O(N)
//Space Complexity : O(N)