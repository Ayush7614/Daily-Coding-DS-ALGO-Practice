// Question  https://leetcode.com/problems/linked-list-cycle-ii/submissions/

// Example 
/*
  Example 1:
  Input: head = [3,2,0,-4], pos = 1
  Output: tail connects to node index 1
  Explanation: There is a cycle in the linked list, where tail connects to the second node.

  Example 2:
  Input: head = [1,2], pos = 0
  Output: tail connects to node index 0
  Explanation: There is a cycle in the linked list, where tail connects to the first node.
*/

// Solution

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        ListNode fast=head, slow=head;
        
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){
                while(head!=null){
                    if(slow==head){
                        return head;
                    }
                    slow=slow.next;
                    head=head.next;
                }
            }
        }
        
        return null;
    }
}