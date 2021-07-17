//  Problem Link : https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//here we have used tortoise algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
      //checking if head is null or head's next is null or not
        if(head==NULL || head->next==NULL)
        {
            return false;
        }
      //pointing fast and slow to head
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next)
        {
          //fast will move by 2 pointers and slow will move by one pomiter
            fast=fast->next->next;
            slow=slow->next;
          //when both comes at same time just return true
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
        
    }
};
//Test cases
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
  
  
//   Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
  
  
