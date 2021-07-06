#Python print prime numbers till n 
def SieveOfEratosthenes(n):
 

    # initialize a boolean array and make all the elements true 

    primeno = [True for j in range(n+1)]

    p = 2#we have to start searching from 2

    while (p * p <= n):

        if (primeno[p] == True):
 

            # make multiples of p false

            for i in range(p * p, n+1, p):

                primeno[i] = False

        p += 1#increment p
 

    # Print all prime numbers

    for p in range(2, n+1):

        if primeno[p]: # Print all the numbers which are true.

            print(p)
 
 


if __name__ == '__main__':

    n =int(input("Enter n : "))

    print("The prime numbers till {} are as follows".format(n))

    SieveOfEratosthenes(n)
    
    
#Example
#Input:20
#Output:Prime numbers till 20 are as follows 
#2 3 5 7 11 13 17 19