//There are a lots of method to  find the prime number till n .
//But Sieve of Eratosthenes is one of the efficient method to do the same.
// C++ program to print all primes
// smaller than or equal to n using Sieve.
//here we mark all multiples of prime number 
//and the number unmarked at end is prime number.
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

void SieveOfEratosthenes(int n)
{       //create an array and store 0 in it.
	int prime[n+1]={0};
	
	for (int i = 2; i<=sqrt(n); i++)
	{// till sqrt(n),if the number isn't prime, it will come with one common factor atleast,if not then it is a prime number.
		// If prime[p] is assigned 0,indexes which doesn't changes its values 
		// then it is a prime
		if (prime[i] == 0)
		{
			// Update all multiples of i
			// less than the sqrt of n.
			// numbers which are multiple
			// of i and are less than n
			// are already been marked.
			for (int j = i*i; j <= n; j+= i) //int j=pow(prime[i],2)----- pow() function in math.h header calculates the power of a number.
				prime[j] = 1;
		}
	}

	// Print all prime numbers 
	for (int i = 2; i <= n; i++)
		if (prime[i]==0)
			cout << i<< " ";

}

// Driver Code
int main()
{
	int n ;
	cout<<"enter the number to get prime number smaller than or equal to it"<<endl;
	cin>>n;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}
