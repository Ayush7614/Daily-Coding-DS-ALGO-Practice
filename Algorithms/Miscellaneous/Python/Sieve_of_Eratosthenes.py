# Python program to print all primes smaller than or equal to n using Sieve of Eratosthenes
# Time complexity : O(n*log(log(n)))

def SieveOfEratosthenes(n):
      
    # Create a boolean array "prime[0..n]" and initialize all entries it as true.
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
              
            # Update all multiples of p to false
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1

    prime[0]= False
    prime[1]= False
    # Print all prime numbers
    for p in range(n + 1):
        if prime[p]:
            print(p)
  

# Taking input from user
n = int(input("Enter a number : "))

print("All primes less than or equal to", n , ": ")

# Calling a function that will print all prime numbers upto n
SieveOfEratosthenes(n) 
