// C++ Program to print all numbers smaller than or equal to n
// Using SieveOfEratosthenes
// Time complexity : O(n*log(log(n))) 



#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	// Firstly creating a boolean array 
	// "prime[0..n]" and initializing
	// all entries it as true.
	
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
  
  // memset is used here to assign all values in boolean array to true
  // now if the value is true than that number is prime 
  // otherwise that number is not a prime number
  
	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed to false 
		// then it is a prime
		if (prime[p] == true)
		{
     
      // here we are updating all the multiples of p which are greater than or eqyal to the square 
      // of it. 
      // Numbers which are multiple of p and are less than (p^2) are marked previously
      // so to save time we need not to mark them again 
      
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Now this Loop is to print all prime number's which we have generated above
  
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << ", ";
}


int main()
{
	int n = 50;
	cout << "All  prime numbers smaller "
		<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);      //  SieveOfEratosthenes function is called to print the prime number's
	return 0;
}

/*
  
  OUTPUT of this Program for n =50 :
  All prime numbers smaller than or equal to 50
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
  
*/


