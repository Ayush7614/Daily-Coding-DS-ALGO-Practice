# CODE DESCRIPTION
# A number is called lucky if the sum of its digits, as well as the sum of the squares of its digits is a prime number.
# Through this python code we can find how many numbers between a and b inclusive, are lucky.

# EXAMPLE
# For example, a = 20 and b = 25 .

# VALUE   SUM OF DIGITs     SQUARE OF DIGITS      SUM 
#  20          2                  4,0              4
#  21          3                  4,1              5
#  22          4                  4,4              8
#  23          5                  4,9              13
#  24          6                  4,16             20
#  25          7                  4,25             29

# We see that three numbers 21, 23 and 25 are lucky.

# Function that gives sum of digits of numbers
def getSum(n):      
    sum = 0
    for digit in str(n):  
      sum += int(digit)       
    return sum

# Function that gives sum of squares of digits of numbers
def getSquareSum(n):      
    SquareSum = 0
    for digit in str(n):  
      SquareSum += int(digit)*int(digit)       
    return SquareSum

# Function that check number is prime or not
def checkPrime(number):
    isPrime = False
    if number == 2:
        isPrime = True
    if number > 2:
        isPrime = True
        for i in range(2, number):
            if number % i == 0:
                isPrime = False
                break
    return isPrime

# Defining a function that returns all lucky numbers
def lucky_number(a,b):
# DECLARING EMPTY LISTS
    # List to store sum and sum of squares of digits of numbers
    FullList=[]

    # List to store final lucky numbers
    primeList=[]

    # For loop to append sum and sum of squares of digits of numbers in FullList
    for i in range(a,b+1):
        sumList=[getSum(i),getSquareSum(i)]
        FullList.append(sumList)

    # Declaring a counter
    counter=0

    # For loop for storing all lucky numbers into primeList
    for i in range(a,b+1):
        if checkPrime(FullList[counter][0]) and checkPrime(FullList[counter][1]):
            primeList.append(i)
        counter+=1

    #return primeList
    return primeList

# Main function
def main():
    # Taking input from users
    a=int(input("Enter the lower bound number :"))
    b=int(input("Enter the upper bound number :"))

    # Calling lucky_number function
    listLucky=lucky_number(a,b)

    # Printing values of lucky number
    if len(listLucky)==0:
        print("There is no lucky number in your range.")
    elif len(listLucky)==1:
        print(f"There is only one Lucky Number that is : {listLucky[0]}",end="")
    else:
        print("Lucky Numbers are : ",end="")
        print(*listLucky)

## To check if the file contains the main function and then calling it
if __name__ == '__main__':
    testcase=int(input("Enter the number of Test cases : "))
    tc=1
    while(tc<=testcase):
        main()
        tc+=1
#OUTPUT
# Enter the lower bound number :1
# Enter the upper bound number :20
# Lucky Numbers are : 11, 12, 14, 16, 
