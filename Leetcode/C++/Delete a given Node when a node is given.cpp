
// Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      //copy the node into the given node.
        
        node->val=node->next->val;
        //point the node to the null to delete it.
        node->next=node->next->next;
    }
};

// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
// Example 3:

// Input: head = [1,2,3,4], node = 3
// Output: [1,2,4]
// Example 4:

// Input: head = [0,1], node = 0
// Output: [1]
// Example 5:

// Input: head = [-3,5,-99], node = -3
// Output: [5,-99]
