
#Problem link : https://leetcode.com/problems/reverse-integer/
def reverse(x):
    s = str(abs(x))
    ans = int (s[::-1])
    if (ans > (pow(2,31)-1) or ans < pow(2,-31)):
        return 0
    elif (x >= 0):
        return ans
    return ans - 2*ans




num = int(input())
print(reverse(num))

#Example test case
# Input : 123
# Output : 321
# Input :  - 123
# Output : -321
