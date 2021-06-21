
# Python program to check if the number is an Armstrong number or not

# take input from the user
num = int(input("Enter a number: "))
# Changed num variable to string, 
# and calculated the length (number of digits)
order = len(str(num))
# initialize sum
sum = 0
# find the sum of the cube of each digit
cube= num
while cube > 0:
   digit = cube % 10
   sum += digit ** order
   cube //= 10

# display the result
if num == sum:
   print(num,"is an Armstrong number")
else:
   print(num,"is not an Armstrong number")
# ex-1
# Enter a number: 153
# 153 is an Armstrong number
# ex-2
# Enter a number: 121
# 121 is not an Armstrong number
