// Question  https://leetcode.com/problems/swap-nodes-in-pairs/

/*
   Given a linked list, swap every two adjacent nodes and return its head.
   You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

// Examples
/*
   Example 1:
   Input: head = [1,2,3,4]
   Output: [2,1,4,3]

   Example 2:
   Input: head = []
   Output: []
*/

// Solution

import java.util.Scanner;

class LinkedList {
    ListNode head; // head of list

    /* Linked list Node*/
    static class ListNode {
        int data;
        ListNode next;
        ListNode(int d)
        {
            data = d;
            next = null;
        }
    }

    public ListNode swapPairs(ListNode head) {                               // Swap pairs
        if(head==null || head.next==null)
            return head;

        ListNode newHead = head.next, a=head, b=a.next, pre = null;

        while(a!=null && b!=null){
            a.next = b.next;
            b.next = a;
            if(pre!=null) pre.next = b;
            if(a.next==null) break;
            b = a.next.next;
            pre = a;
            a = a.next;
        }

        return newHead;
    }

    public void push(int new_data)
    {
        ListNode new_node = new ListNode(new_data);
        ListNode temp = head;

        while(temp.next != null)
        {
            temp = temp.next;
        }

        temp.next = new_node;
    }

    public void printList()
    {
        ListNode tnode = head;
        while (tnode != null) {
            System.out.print(tnode.data + " ");
            tnode = tnode.next;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);

        LinkedList llist = new LinkedList();

        System.out.println("\nEnter Linked list size:");
        int n = sc.nextInt();

        if(llist.head == null)
        {
            int e = sc.nextInt();
            ListNode new_node =new ListNode(e);
            llist.head = new_node;
        }

        for(int i = 1;i < n;i ++)
        {
            int e = sc.nextInt();
            llist.push(e);
        }

        System.out.println("Created Linked list is:");
        llist.printList();

        ListNode res = llist.swapPairs( llist.head );                        // swap node with data

        System.out.println("Linked list after Swapped:");

        while (res != null) {
            System.out.print(res.data + " ");
            res = res.next;
        }
    }
}
