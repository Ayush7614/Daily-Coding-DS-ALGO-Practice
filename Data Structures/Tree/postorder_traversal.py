ans=[]

#create a new node
class Node: 

    def __init__(self, data): 

        self.data = data 

        self.left = None

        self.right = None
 
#top of stack 
def peek(s): 

    if len(s) > 0: 

        return s[-1] 

    return None

def postOrderTraversal(root): 

    # if tree is empty
    if root is None: 

        return
 
    s= [] 

    while(True): 

        while (root): 

            # append right child to the stack if right is not empty 

            if root.right is not None: 

                s.append(root.right) 

            s.append(root) 
 

            # Set root as root's left child 

            root = root.left 

         

        # remove an item from stack and set it as root 

        root = s.pop() 
 

        # If the removed element has a right child and the  right child is not traversed yet, then make sure right child is traversed before root 

        if (root.right is not None and

            peek(s) == root.right): 

            s.pop() # Remove right child from stack 

            s.append(root) # append root back to stack 

            root = root.right # change root so that the  right child is traversed next 
 

        # print root's data and set root as None 

        else: 

            ans.append(root.data) 

            root = None
 

        if (len(s) <= 0): 

                break
 
# Driver program to test above function 

root = Node(1) 

root.left = Node(2) 

root.right = Node(3) 

root.left.left = Node(4) 

root.left.right = Node(5) 

root.right.left = Node(6) 

root.right.right = Node(7) 
 

print("Post Order traversal of binary tree is")
postOrderTraversal(root) 

print(ans)
#Output:
# [4,5,2,6,7,3,1]
  