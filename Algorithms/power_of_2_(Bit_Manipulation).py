# Python program to check if given
# number is power of 2 or not

 ''' If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset.

For example for 4 ( 100) and 16(10000), we get following after subtracting 1
3 –> 011
15 –> 01111


'''



# This Function Checks if the given x is power of 2 or not
def isPowerOfTwo (x):
  
    # First x in the below expression 
    # is for the case when x is 0 
    return (x and (not(x & (x - 1))) )
  
# Simple Conditions to check which will call ispowerofTwo
n=int(input("Enter Number \n"))

if(isPowerOfTwo(n)):
    print('YES')
else:
    print('NO')
      
