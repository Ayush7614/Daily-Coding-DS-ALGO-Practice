def myAtoi(string):
    result = 0
    sign = 1
    i = 0
    if string[0] == '-':
        sign = -1
        i += 1
    for j in range(i,len(string)):
            result = result*10+(ord(string[j])-ord('0'))
    return sign * result
string =input("Enter string")
print (myAtoi(string))
"""
Testcase-1: 
Enter String: "-8479"
Output: -8479

Testcase-2:
Enter String:"124"
Output: 124

TimeComplexity:O(n)
Space complexity:O(1)
"""