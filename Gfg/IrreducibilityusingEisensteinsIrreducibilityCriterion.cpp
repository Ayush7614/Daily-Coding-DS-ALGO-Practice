// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to to implement the sieve
// of eratosthenes
vector<int> SieveOfEratosthenes(int M)
{
	// Stores the prime numbers
	bool isPrime[M + 1];

	// Initialize the prime numbers
	memset(isPrime, true,
		sizeof(isPrime));

	for (int p = 2; p * p <= M; p++) {

		// If isPrime[p] is not changed,
		// then it is a prime
		if (isPrime[p] == true) {

			// Update all multiples of
			// p as non-prime
			for (int i = p * p;
				i <= M; i += p) {
				isPrime[i] = false;
			}
		}
	}

	// Stores all prime numbers less
	// than M
	vector<int> prime;

	for (int i = 2; i <= M; i++) {

		// If the i is the prime numbers
		if (isPrime[i]) {
			prime.push_back(i);
		}
	}

	// Return array having the primes
	return prime;
}

// Function to check whether the three
// conditions of Eisenstein's
// Irreducibility criterion for prime P
bool check(int A[], int P, int N)
{
	// 1st condition
	if (A[0] % P == 0)
		return 0;

	// 2nd condition
	for (int i = 1; i < N; i++)
		if (A[i] % P)
			return 0;

	// 3rd condition
	if (A[N - 1] % (P * P) == 0)
		return 0;

	return 1;
}
// Function to check for Eisensteins
// Irreducubility Criterion
bool checkIrreducibilty(int A[], int N)
{
	// Stores the largest element in A
	int M = -1;

	// Find the maximum element in A
	for (int i = 0; i < N; i++) {
		M = max(M, A[i]);
	}

	// Stores all the prime numbers
	vector<int> primes
		= SieveOfEratosthenes(M + 1);

	// Check if any prime
	// satisfies the conditions
	for (int i = 0;
		i < primes.size(); i++) {

		// Function Call to check
		// for the three conditions
		if (check(A, primes[i], N)) {
			return 1;
		}
	}
	return 0;
}

// Input Code
int main()
{
	int A[] = { 4, 7, 21, 28 };
	int N = sizeof(A) / sizeof(A[0]);
	cout << checkIrreducibilty(A, N);

	return 0;
}
