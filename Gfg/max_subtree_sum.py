#Program to find Maximum possible subtree sum in a tree

class newNode: 

    def __init__(self, key): 

        self.key = key  

        self.left = self.right = None

  

def findLargestSubtreeSumUtil(root, ans): 

      

    # If current node is None then  

    # return 0 to parent node.  

    if (root == None):  

        return 0

      

    # Subtree sum rooted at current node.  

    currSum = (root.key + 

               findLargestSubtreeSumUtil(root.left, ans) + 

               findLargestSubtreeSumUtil(root.right, ans))  

  

    # Update answer if current subtree  

    # sum is greater than answer so far.  

    ans[0] = max(ans[0], currSum)  

  

    # Return current subtree sum to  

    # its parent node.  

    return currSum 

  


def findLargestSubtreeSum(root): 

      

    # If tree does not exist,  

    # then answer is 0.  

    if (root == None):      

        return 0

      

    # Variable to store maximum subtree sum.  

    ans = [-999999999999] 

  

    # Call to recursive function to  

    # find maximum subtree sum.  

    findLargestSubtreeSumUtil(root, ans)  

  

    return ans[0] 

  


if __name__ == '__main__': 

      



    root = newNode(1)  

    root.left = newNode(-2)  

    root.right = newNode(3)  

    root.left.left = newNode(4)  

    root.left.right = newNode(5)  

    root.right.left = newNode(-6)  

    root.right.right = newNode(2)  

  

    print(findLargestSubtreeSum(root))
    
    
    
    #  

    #         1  

    #         / \  

    #     /     \  

    #     -2     3  

    #     / \     / \  

    #     / \ / \  

    # 4     5 -6     2