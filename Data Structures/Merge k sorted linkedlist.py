import heapq
from heapq import heappop, heappush
 
 
# A Linked List Node
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
 
    # Override the `__lt__()` function to make `Node` class work with min-heap
    def __lt__(self, other):
        return self.data < other.data
 
 
# Utility function to print contents of a linked list
def printList(node):
    while node:
        print(node.data, end=' —> ')
        node = node.next
 
    print("None")
 
 
# The main function to merge given `k` sorted linked lists.
def mergeKs(list):
  # create a min-heap using the first node of each list
    pq = [x for x in list]
    heapq.heapify(list)
 
    # take two pointers, head and tail, where the head points to the first node
    # of the output list and tail points to its last node
    head = None
    last = None
 
    # run till min-heap is empty
    while pq:
 
        # extract the minimum node from the min-heap
        min = heappop(pq)
 
        # add the minimum node to the output list
        if head is None:
            head = min
            last = min
        else:
            last.next = min
            last = min
 
        # take the next node from the "same" list and insert it into the min-heap
        if min.next:
            heappush(pq, min.next)
 
    # return head node of the merged list
    return head
 
 
if __name__ == '__main__':
 
    # total number of linked lists
    k = 3
 
    # a list to store the head nodes of the linked lists
    lists = [None] * k
 
    lists[0] = Node(1)
    lists[0].next = Node(5)
    lists[0].next.next = Node(7)
 
    lists[1] = Node(2)
    lists[1].next = Node(3)
    lists[1].next.next = Node(6)
    lists[1].next.next.next = Node(9)
 
    lists[2] = Node(4)
    lists[2].next = Node(8)
    lists[2].next.next = Node(10)
 
    # Merge all lists into one
    head = mergeKs(lists)
    printList(head)
 


# Output 
1 —> 2 —> 3 —> 4 —> 5 —> 6 —> 7 —> 8 —> 9 —> 10 —> None

# Time Complexity : O(n.log(k))



