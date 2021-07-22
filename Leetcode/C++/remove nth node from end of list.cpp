//Link to the problem
/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/                              */

//According to the problem:

//Given the head of a linked list

//AIM:  Remove the nth node from the end of the list and return its head.

/*Sample Example :
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * start= new ListNode();
        start->next=head;
        int val=0;
        ListNode* slow=start,*fast=start;
        //taking the fast pointer to nth position from start
        while(val!=n)
        {
            fast= fast->next;
            val++;
        }
        //while the fast pointer will reach to the end of the list, slow pointer reaches to to the node to be removed
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //connected the next of slow to next of to be deleted node
        slow->next=slow->next->next;
        //returning the new required Linked list
        return start->next;
    }
};