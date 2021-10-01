/*You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

Example-
Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.*/


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums)
    {
        unordered_set<int>present(nums.begin(),nums.end());
        ListNode *temp=head;
        int count=0;
        while(temp)
        {
            while(temp && present.find(temp->val)==present.end())//ignore missing elements
                temp=temp->next;
            if(temp)
            {
                while(temp && present.find(temp->val)!=present.end())//counting connected elements
                    temp=temp->next;
                count++;
            }
        }
        return count;
    }
};