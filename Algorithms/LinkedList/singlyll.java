package Algorithms.LinkedList;

public class singlyll {

    Node head;
    class Node {
        int item;
        Node next;

        Node(int d) {
            item = d;
            next = null;
        }
    }
    public void insertAtBeginning(int data) {
        // insert the item
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }

    public void insertAfter(Node prev_node, int data) {
        if (prev_node == null) {
            System.out.println("The given previous node cannot be null");
            return;
        }
        Node new_node = new Node(data);
        new_node.next = prev_node.next;
        prev_node.next = new_node;
    }

    public void insertAtEnd(int data) {
        Node new_node = new Node(data);

        if (head == null) {
            head = new Node(data);
            return;
        }

        new_node.next = null;

        Node last = head;
        while (last.next != null)
            last = last.next;

        last.next = new_node;
        return;
    }

    void deleteNode(int position) {
        if (head == null)
            return;

        Node node = head;

        if (position == 0) {
            head = node.next;
            return;
        }
        // Find the key to be deleted
        for (int i = 0; node != null && i < position - 1; i++)
            node = node.next;

        // If the key is not present
        if (node == null || node.next == null)
            return;

        // Remove the node
        Node next = node.next.next;

        node.next = next;
    }

    public void printList(Node node) {
        //Node node = head;
        while (node != null) {
            System.out.print(node.item + " ");
            node = node.next;
        }
    }
    Node reverse(Node node)
    {
        Node prev=null;
        Node curr=head;
        Node next=null;
        while(curr!=null)
        {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        node=prev;
        return node;
    }
    public static  int search(int number,Node head)
    {

        if(head==null)
        {
            return -1;
        }
        Node temp=head;
        int index=0;//it will help us to return the index of the position if found
        while(temp!=null)
        {
            if(temp.item==number)
            {
                return index;
            }
            index++;
            temp=temp.next;
        }
        return -1;

    }
    public static Node getmiddle(Node head)
    {
        if(head==null)
        {
            return head;
        }
        Node slow=head;
        Node fast=head.next;
        while(fast!=null&&fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    Node merge(Node node)
    {
        if(node==null||node.next==null)
        {
            return node;
        }
        Node middle=getmiddle(node);
        Node middlenext=middle.next;
        middle.next=null;
        Node firstpart=merge(node);
        Node secondpart=merge(middlenext);
        return mergesort(firstpart,secondpart);
    }
    Node mergesort(Node a,Node b)
    {
        if(a==null)
        {
            return b;
        }
        if(b==null)
        {
            return a;
        }
        Node result=null;
        if(a.item<=b.item)
        {
            result=a;
            result.next=mergesort(a.next,b);
        }
        else
        {
            result=b;
            result.next=mergesort(a,b.next);
        }
        return result;
    }



    public static void main(String[] args) {
        singlyll llist = new singlyll();

        llist.insertAtEnd(1);
        llist.insertAtBeginning(2);
        llist.insertAtBeginning(3);
        llist.insertAtEnd(4);
        llist.insertAfter(llist.head.next, 5);

        System.out.println("Linked list: ");
        llist.printList(llist.head);

        System.out.println("\nAfter deleting an element: ");
        llist.deleteNode(3);
        llist.printList(llist.head);
        llist.head=llist.reverse(llist.head);
        System.out.println("\n After reversing the element are");
        llist.printList(llist.head);
       

    }
}
