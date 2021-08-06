
// problem link :- https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //create a dumy node and also a temp node which will point to the dumy node 
        ListNode* dumy=  new ListNode();
        ListNode*temp=dumy;
        //initialize carry with 0
        int carry=0;
        //if l1 or l2 or carry will be null it will simply return the duy node
        while(l1!=NULL || l2!=NULL || carry)
        {
            //intialise the sum to 0
            int sum=0;
            //if l1 is not null than add into sum variable 
            if(l1!=NULL)
            {
                sum+=l1->val;
                //and move next
                l1=l1->next;
            }
            //if l2 is not null than add into sum varibale
            if(l2!=NULL)
            {
                //move to next 
                sum+=l2->val;
                l2=l2->next;
            }
            //add carry to sum
            sum+=carry;
            //as we know for adding the carry we have to do sum /10
            carry=sum/10;
            //crete a node
            ListNode  *node = new ListNode(sum%10);
            //link it to the temp node
            temp->next=node;
            temp=temp->next;
            
        }
        //simply returning the dumy node.
        return dumy->next;
    }
};
