#Program to merge 2 sorted linked lists
#Problem link :- https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
class Node:

    def __init__(self, data):

        self.data = data

        self.next = None
 
 
# Create a linked list 

class LinkedList:
    def __init__(self):
        self.head = None
    #  display the list
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
 
    #  add element to list
    def addList(self, newData):
        newNode = Node(newData)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode
 
 
# merge two sorted lists.

def mergeLists(headA, headB):
 

    # A dummy node to store the result

    dummyNode = Node(0)
 

    # stores the last node

    tail = dummyNode

    while True:
 

        # If any of the list gets  empty directly join all the elements of the other list

        if headA is None:
            tail.next = headB
            break

        if headB is None:
            tail.next = headA
            break
 

        #Compare the list and the smaller data  is added to the last of the merged list and the head is changed

        if headA.data <= headB.data:
            tail.next = headA
            headA = headA.next

        else:
            tail.next = headB
            headB = headB.next
 

        # tail points to next 

        tail = tail.next
 

    # Returns the head of the merged list

    return dummyNode.next
 
 
# Create 2 linked  lists

listA = LinkedList()

listB = LinkedList()
 
# Add elements to the list in sorted order

listA.addList(5)

listA.addList(10)

listA.addList(15)
 

listB.addList(2)

listB.addList(3)

listB.addList(20)
 
# Call the merge function

listA.head = mergeLists(listA.head, listB.head)
 
# Display merged list

print("Merged Linked List is:")
listA.printList()


#Output:2 3 5 10 15 20 
