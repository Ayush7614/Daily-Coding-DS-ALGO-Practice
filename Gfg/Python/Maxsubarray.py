#Program to find max subarray in python 
def maxSubArraySum(a, size): 

      

    max_so_far = 0

    max_ending_here = 0

      

    for i in range(0, size): 

        max_ending_here = max_ending_here + a[i] 

        if max_ending_here < 0: 

            max_ending_here = 0

        elif (max_so_far < max_ending_here): 

            max_so_far = max_ending_here 

              

    return max_so_far 
    
a=[]
n=int(input("size"))
for i in range(n):
  b=int(input("Enter array element"))
  a.append(b)
print(maxSubArraySum(a,n))


#Example 
#size 5
# 100 100 300 -500 -100 
#output 500 