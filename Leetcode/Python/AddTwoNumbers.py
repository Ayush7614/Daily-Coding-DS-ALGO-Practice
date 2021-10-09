'''You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.'''

'''Input: l1 = [2,4,3], l2 = [5,6,4]
   Output: [7,0,8]
   Explanation: 342 + 465 = 807.'''


'''Input: l1 = [0], l2 = [0]
   Output: [0]'''

'''Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
   Output: [8,9,9,9,0,0,0,1]'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        #to keep track of position of digit in the number1
        count=1

        #to keep track of position of digit in the number1
        count1=1

        k=0
        l=0

        #store the number1 in k
        while l1:
            k+=l1.val*count
            l1=l1.next
            count=count*10

        #store the number2 in l
        while l2:
            l+=l2.val*count1
            l2=l2.next
            count1*=10

        #store the result
        res=k+l

        #store the number of digits in result
        d=len(str(res))
        g=[]
        while res!=0:
            h=res%10
            res=res//10
            newnode=ListNode(h)
            g.append(newnode)
        else:
            #else condition if the numbers are empty lists and the result is zero to return emptylist
            newnode=ListNode(res)
            g.append(newnode)
            #linking every nodes to form a list containing result
        for i in range(d-1):
            g[i].next=g[i+1]
        return g[0]






