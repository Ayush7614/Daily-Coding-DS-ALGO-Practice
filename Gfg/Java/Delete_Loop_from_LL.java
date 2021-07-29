// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
// Remove the loop from the linked list, if it is present.  

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|    
// A loop is present. If you remove it 
// successfully, the answer will be 1. 

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not 
// contains any loop. 

// { Driver Code Starts
// driver code

import java.util.*;

class Node {
    int data;
    Node next;
}

class Delete {
    public static Node newNode(int data) {
        Node temp = new Node();
        temp.data = data;
        temp.next = null;
        return temp;
    }

    public static void makeLoop(Node head, int x) {
        if (x == 0)
            return;
        Node curr = head;
        Node last = head;

        int currentPosition = 1;
        while (currentPosition < x) {
            curr = curr.next;
            currentPosition++;
        }

        while (last.next != null)
            last = last.next;
        last.next = curr;
    }

    public static boolean detectLoop(Node head) {
        Node hare = head.next;
        Node tortoise = head;
        while (hare != tortoise) {
            if (hare == null || hare.next == null)
                return false;
            hare = hare.next.next;
            tortoise = tortoise.next;
        }
        return true;
    }

    public static int length(Node head) {
        int ret = 0;
        while (head != null) {
            ret += 1;
            head = head.next;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();

            int num = sc.nextInt();
            Node head = newNode(num);
            Node tail = head;

            for (int i = 0; i < n - 1; i++) {
                num = sc.nextInt();
                tail.next = newNode(num);
                tail = tail.next;
            }

            int pos = sc.nextInt();
            makeLoop(head, pos);

            ans x = new ans();
            x.removeLoop(head);

            if (detectLoop(head) || length(head) != n)
                System.out.println("0");
            else
                System.out.println("1");
        }
    }
}
// } Driver Code Ends

/*
 * class Node { int data; Node next; }
 */

// Solution -

class ans {
    public static void removeLoop(Node head) {
        if (head == null || head.next == null)
            return;

        Node slow = head, fast = head;

        // Search for loop using slow and fast pointers
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                remove(head, fast, slow);
                break;
            }
        }
    }

    private static void remove(Node head, Node fast, Node slow) {
        if (slow == fast) {
            slow = head;
            if (slow != fast) {
                while (slow.next != fast.next) {
                    slow = slow.next;
                    fast = fast.next;
                }
                // since fast->next is the looping point
                fast.next = null; /* remove loop */
            }
            // if fast and slow pointer meet at first position.
            else {
                while (fast.next != slow) {
                    fast = fast.next;
                }
                fast.next = null;
            }
        }
    }
}

// time complexity : O(N)
// auxiliary space : O(1)