
//Problem Link : https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //finding the middle of the linklist
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reversing the linklist
        ListNode*ptr=NULL;
        ListNode*next=NULL;
        while(slow!=NULL)
        {
            next=slow->next;
            slow->next=ptr;
            ptr=slow;
            slow=next;
        }
        //checking the reversed middle point
        while(ptr!=NULL)
        {
            if(head->val != ptr->val)
            {
                return false;
            }
            head=head->next;
            ptr=ptr->next;
        }
        return true;
    }
};
//Testcase
// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
