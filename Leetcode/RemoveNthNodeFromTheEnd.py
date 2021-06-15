'''Given the head of a linked list, remove the nth node from the end of the list and return its head.''''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
		#nth node which we have to delete
        node = head  
		# last node it will reach to the end first at the same time nth node will be on the node that needs to be deleted
        lastNode = head 
		 # it will store the previous node whose .next will be updated in order to delete nth node
        preNode = head
		#skip node so that in sigle traversal we will have nth node
        while n>1:
            lastNode = lastNode.next
            n -= 1
        
        while lastNode.next is not None:
            preNode = node
            node = node.next
            lastNode = lastNode.next
            
		#special handling for linked list size 1 and 2
        if preNode == node and node == lastNode:
            # if all the three are at same point that means linked list has 1 item
			head = None
        elif node == preNode:
			#if node and previous are on same item and last node is difrrent that means there are 2 item
            head = node.next
        else:
            preNode.next = node.next
            
        
        return head