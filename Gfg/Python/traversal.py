**_### # Python program for diagonal traversal of Binary Tree

Diagonal Traversal of Binary Tree

A binary tree node_**
class Node:

# Constructor to create a new binary tree node

def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
"

# Base Case to check if it is true or false
if root is None:
    return


 #using exceptionally handling with try or except 
try :
    diagonalPrintMap[d].append(root.data)
except KeyError:
    diagonalPrintMap[d] = [root.data]


# if left child
diagonalPrintUtil(root.left,
                    d+1, diagonalPrintMap)
 

# same for right child
diagonalPrintUtil(root.right,
                       d, diagonalPrintMap)
Print diagonal traversal of given binary tree
def diagonalPrint(root):

# Create a dict to store diagnoal elements
diagonalPrintMap = dict()
 
# Find the diagonal traversal
diagonalPrintUtil(root, 0, diagonalPrintMap)

print "Diagonal Traversal of binary tree : "
for i in diagonalPrintMap:
    for j in diagonalPrintMap[i]:
        print j,
    print ""
giving the input in the console itself
root = Node(8)
root.left = Node(3)
root.right = Node(10)
root.left.left = Node(1)
root.left.right = Node(6)
root.right.right = Node(14)
root.right.right.left = Node(13)
root.left.right.left = Node(4)
root.left.right.right = Node(7)

diagonalPrint(root)