n=int(input("Enter number:")) # take input from user
temp=n
rev=0
while(n>0):
    dig=n%10 #extract digits
    rev=rev*10+dig#reverse digits
    n=n//10
if(temp==rev):
    print("The number is a palindrome!")
else:
    print("The number isn't a palindrome!")