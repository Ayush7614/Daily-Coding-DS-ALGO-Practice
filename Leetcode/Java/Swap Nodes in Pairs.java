// Question  https://leetcode.com/problems/swap-nodes-in-pairs/
/*
   Given a linked list, swap every two adjacent nodes and return its head.
   You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

// Exapmple
/*
   Example 1:
   Input: head = [1,2,3,4]
   Output: [2,1,4,3]
   
   Example 2:
   Input: head = []
   Output: []
*/

// Solution

public class Solution {
  public ListNode swapPairs(ListNode head) {
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
}