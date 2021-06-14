/* C++ Program to answer Q queries to
find number of times an element x
appears x times in a Query subarray */

#include <bits/stdc++.h>
using namespace std;

// Variable to represent block size.
// This is made global so compare()
// of sort can use it.

int block;

// Structure to represent a query range

struct Query {
	int L, R, index;
};

/* Function used to sort all queries
so that all queries of same block
are arranged together and within
a block, queries are sorted in
increasing order of R values. */

bool compare(Query x, Query y)
{
	// Different blocks, sort by block.
	if (x.L / block != y.L / block)
		return x.L / block < y.L / block;

	// Same block, sort by R value
	return x.R < y.R;
}

/* Inserts element (x) into current range
and updates current answer */

void add(int x, int& currentAns,
		unordered_map<int, int>& freq)
{

	// increment frequency of this element
	freq[x]++;

	// if this element was previously
	// contributing to the currentAns,
	// decrement currentAns

	if (freq[x] == (x + 1))
		currentAns--;

	// if this element has frequency
	// equal to its value, increment
	// currentAns

	else if (freq[x] == x)
		currentAns++;
}

/* Removes element (x) from current
range btw L and R and updates
current Answer */

void remove(int x, int& currentAns,
			unordered_map<int, int>& freq)
{

	// decrement frequency of this element
	freq[x]--;

	// if this element has frequency equal
	// to its value, increment currentAns
	if (freq[x] == x)
		currentAns++;

	// if this element was previously
	// contributing to the currentAns
	// decrement currentAns
	else if (freq[x] == (x - 1))
		currentAns--;
}

/* Utility Function to answer all queries
and build the ans array in the original
order of queries */

void queryResultsUtil(int a[], Query q[],
						int ans[], int m)
{

	// map to store freq of each element
	unordered_map<int, int> freq;

	// Initialize current L, current R
	// and current sum
	int currL = 0, currR = 0;
	int currentAns = 0;

	// Traverse through all queries
	for (int i = 0; i < m; i++) {
		// L and R values of current range
		int L = q[i].L, R = q[i].R;
		int index = q[i].index;

		// Remove extra elements of previous
		// range. For example if previous
		// range is [0, 3] and current range
		// is [2, 5], then a[0] and a[1] are
		// removed

		while (currL < L) {
			remove(a[currL], currentAns, freq);
			currL++;
		}

		// Add Elements of current Range
		while (currL > L) {
			currL--;
			add(a[currL], currentAns, freq);
		}
		while (currR <= R) {
			add(a[currR], currentAns, freq);
			currR++;
		}

		// Remove elements of previous range. For example
		// when previous range is [0, 10] and current range
		// is [3, 8], then a[9] and a[10] are Removed

		while (currR > R + 1) {
			currR--;
			remove(a[currR], currentAns, freq);
		}

		// Store current ans as the Query ans for
		// Query number index
		ans[index] = currentAns;
	}
}

/* Wrapper for queryResultsUtil() and outputs the
ans array constructed by answering all queries */

void queryResults(int a[], int n, Query q[], int m)
{
	// Find block size
	block = (int)sqrt(n);

	// Sort all queries so that queries of same blocks
	// are arranged together.
	sort(q, q + m, compare);

	int* ans = new int[m];
	queryResultsUtil(a, q, ans, m);

	for (int i = 0; i < m; i++) {
		cout << "Answer for Query " << (i + 1)
			<< " = " << ans[i] << endl;
	}
}

// Driver program

int main()
{
	int A[] = { 1, 2, 2, 3, 3, 3 };

	int n = sizeof(A) / sizeof(A[0]);

	// 2D array of queries with 2 columns
	Query queries[] = { { 0, 1, 0 },
						{ 1, 1, 1 },
						{ 0, 2, 2 },
						{ 1, 3, 3 },
						{ 3, 5, 4 },
						{ 0, 5, 5 } };

	// calculating number of queries
	int q = sizeof(queries) / sizeof(queries[0]);

	// Print result for each Query
	queryResults(A, n, queries, q);

	return 0;
}
