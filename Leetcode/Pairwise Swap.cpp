class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL)        // empty linked list   
            return NULL;  
        
        if(head->next == NULL)   // 1 node (cannot be swapped)
            return head; 
        
        // 1->2->3->4
        
        ListNode* next = head->next;        // new head i.e. 2
        
        head->next = swapPairs(next->next);     // 2->next = swap(2->next i.e. 3->4 will return 4->3)
        
        next->next = head;  // 2->1
        
        return next; // return 4->3 then 2->1->4->3
    }
};
