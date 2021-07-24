#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Swap Nodes in pairs on LeetCode, solution by AtrikGit6174
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation: 1->2 is swapped; 2 becomes head. 3->4 is swapped. 

Input: head = []
Output: []

Input: head = [1]
Output: [1]

Input: head= [1,2,3]
Output: [2, 1, 3]
Explanation: 1->2 is swapped; 2 becomes head. 3 cannot be swapped and stays as it is.

Constraints:

-- The number of nodes in the list is in the range [0, 100].
-- 0 <= Node.val <= 100
*/

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* createList (vector<int> vec, int n)
    {
        //for testing only. Not needed for solution on LeetCode
        if (!n)
            return nullptr;
        
        auto head= new ListNode (vec[0]);
        
        if (n>1)
        {
            auto ptr= head;
            
            for (int i=1; i<n; i++)
            {
                ptr->next= new ListNode (vec[i]);
                ptr= ptr->next;
            }
        }
        
        return head;
    }
    
    ListNode* swapPairs(ListNode* head) 
    {
        //part of solution   
        if (head and head->next)
            return recSwap (head);
        
        else
            return head;
    }
    
    ListNode* recSwap (ListNode *node)
    {
        //part of solution   
        /*The return type is essentially ListNode* because 
        1. We need the head to the new list in swapPairs
        2. For every call, the previous pointer 
           to the two nodes before swapping points to the next node instead of the previous.
        */
           
        if (!node or !node->next)
            return node;
        
        //swapping
        auto temp1= node->next;
        node->next= temp1->next;
        temp1->next= node;
        
        //some renaming for ease
        auto temp2= node;
        node= temp1;
        temp1= temp2;
        
        temp1->next= recSwap (temp1->next);
        return node;
    }
};

int main() 
{
	cout<<"Enter the number of nodes= ";
	int n; cin>>n;
	vector<int> vec(n);
	
	if (n)
	{
    	cout<<"\nEnter node values: \n";
    	for (int i=0; i<n; i++)
    	    cin>>vec[i];
	}
	
	Solution *ob;
	auto ptr= ob->swapPairs( (!n) ? nullptr : ob->createList (vec,n));
	
	//displaying list
    cout<<"\n[";
	while (ptr)
	{
	   cout<<ptr->val;
	   if (ptr->next)
	        cout<<"->";
	   ptr= ptr->next;
	}
	
	cout<<"]";
	
	return 0;
}
