**_### # Python program for diagonal traversal of Binary Tree

Diagonal Traversal of Binary Tree

A binary tree node_**
class Node:



def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
"


if root is None:
    return


try :
    diagonalPrintMap[d].append(root.data)
except KeyError:
    diagonalPrintMap[d] = [root.data]



diagonalPrintUtil(root.left,
                    d+1, diagonalPrintMap)
 


diagonalPrintUtil(root.right,
                       d, diagonalPrintMap)
Print diagonal traversal of given binary tree
def diagonalPrint(root):


diagonalPrintMap = dict()
 

diagonalPrintUtil(root, 0, diagonalPrintMap)


for i in diagonalPrintMap:
    for j in diagonalPrintMap[i]:
        print j,
    print ""

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


###
///i am adding the test cases

     8  10
  3  6     14
        7
1  4    13

###OUTPUT
 8 10 14
 3 6 7 13
 1 4
    
    
 ///   
    
 ###
