#Problem link : https://leetcode.com/problems/multiply-strings/
def multiply(num1, num2):
    return str(int(num1)*int(num2))


num1,num2 = input().split();
print(multiply(num1,num2))

#Example test case
# Input : "2" "3"
# Output : "6"
