// C++ program for Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
	// jumps[n-1] will hold the result
	int* jumps = new int[n];
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	// Find the minimum number of jumps to reach arr[i]
	// from arr[0], and assign this value to jumps[i]
	for (i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

// Driver code
int main()
{
	int arr[] = { 1, 3, 6, 1, 0, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Minimum number of jumps to reach end in the desired array is "
		<< minJumps(arr, size);
	return 0;
}


