#QUESTION: REVERSE THE CIRCULAR LINKED LIST

#SOLUTION:

import math

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

def getNode(data):

	newNode = Node(data)
	newNode.data = data
	newNode.next = None
	return newNode

def reverse(head_ref):
	
	if (head_ref == None):
		return None
	prev = None
	current = head_ref
	next = current.next
	current.next = prev
	prev = current
	current = next
	while (current != head_ref):
		next = current.next
		current.next = prev
		prev = current
		current = next

	head_ref.next = prev
	head_ref = prev
	return head_ref


def prList(head):
	if (head == None):
		return
	temp = head	
	print(temp.data, end = " ")
	temp = temp.next
	while (temp != head):
		print(temp.data, end = " ")
		temp = temp.next

if __name__=='__main__':
	
	head = getNode(1)
	head.next = getNode(2)
	head.next.next = getNode(3)
	head.next.next.next = getNode(4)
	head.next.next.next.next = head
	print("Before linked list: ")
	prList(head)
	head = reverse(head)
	print("\nAfter circular linked list: ")
	prList(head)






#Before linked list: 1 2 3 4
#After linked list: 4 3 2 1









