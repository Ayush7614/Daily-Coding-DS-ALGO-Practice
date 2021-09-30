// C++ program to find the nth Catalan Number
#include <iostream>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
								unsigned int k)
{
	unsigned long int res = 1;

	if (k > n - k)
		k = n - k;

	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n)
{
	unsigned long int c = binomialCoeff(2 * n, n);

	return c / (n + 1);
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}
