number = int(input("Enter a number: "))

# initialize sum to zero
sum = 0

# find the sum of the cube of each digit
temp = number
while temp > 0:
   digit = temp % 10
   sum += digit ** 3
   temp //= 10

# display the result
if number == sum:
   print(number,"is an Armstrong number")
else:
   print(number ,"is not an Armstrong number")
