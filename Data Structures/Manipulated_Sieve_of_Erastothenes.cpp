//----------MANIPULATED SIEVE OF ERASTOTHENES--------//

/*
The classical Sieve of Eratosthenes algorithm takes O(N log (log N))
time to find all prime numbers less than N. A modified Sieve is
discussed that works in O(N) time.
*/

/*
Modified Sieve works in following way:
```For every number i where i varies from 2 to N-1:
    Check if the number is prime. If the number
    is prime, store it in prime array.

For every prime numbers j less than or equal to the smallest  
prime factor p of i:
    Mark all numbers j*p as non_prime.
    Mark smallest prime factor of j*p as j```
*/

// C++ program to generate all prime numbers
// less than N in O(N)
#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;

// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

// function generate all prime number less then N in O(n)
void manipulated_seive(int N)
{
	// 0 and 1 are not prime
	isprime[0] = isprime[1] = false ;

	// Fill rest of the entries
	for (long long int i=2; i<N ; i++)
	{
		// If isPrime[i] == True then i is
		// prime number
		if (isprime[i])
		{
			// put i into prime[] vector
			prime.push_back(i);

			// A prime number is its own smallest
			// prime factor
			SPF[i] = i;
		}

		/*
         Remove all multiples of i*prime[j] which are
		 not prime by making isPrime[i*prime[j]] = false
		 and put smallest prime factor of i*Prime[j] as prime[j]
		 [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
		 so smallest prime factor of '10' is '2' that is prime[j] ]
		 this loop run only one time for number which are not prime
        */
		for (long long int j=0;
			j < (int)prime.size() &&
			i*prime[j] < N && prime[j] <= SPF[i];
			j++)
		{
			isprime[i*prime[j]]=false;

			// put smallest prime factor of i*prime[j]
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}

// driver program to test above function
int main()
{
	int N = 13 ; // Must be less than MAX_SIZE

	manipulated_seive(N);

	// pint all prime number less then N
	for (int i=0; i<prime.size() && prime[i] <= N ; i++)
		cout << prime[i] << " ";

	return 0;
}
