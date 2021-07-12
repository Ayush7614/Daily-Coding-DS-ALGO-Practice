// C++ program to count the
// no. of ways to place 2*1 size
// tiles in 2*n size board.
#include <iostream>
using namespace std;

int getNoOfWays(int n)
{
	// Base case
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return getNoOfWays(n - 1) + getNoOfWays(n - 2);
}

// Driver Function
int main()
{
	cout << getNoOfWays(4) << endl;
	cout << getNoOfWays(3);
	return 0;
}
