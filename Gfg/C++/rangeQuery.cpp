#include <bits/stdc++.h>
using namespace std;

int block;

// Structure to represent a query range

struct Query {
	int L, R, index;
};

bool compare(Query x, Query y)
{
	// Different blocks, sort by block.
	if (x.L / block != y.L / block)
		return x.L / block < y.L / block;

	// Same block, sort by R value
	return x.R < y.R;
}

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


void queryResultsUtil(int a[], Query q[],
						int ans[], int m)
{

	int currL = 0, currR = 0;
	int currentAns = 0;

	// Traverse through all queries
	for (int i = 0; i < m; i++) {
		// L and R values of current range
		int L = q[i].L, R = q[i].R;
		int index = q[i].index;

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

		while (currR > R + 1) {
			currR--;
			remove(a[currR], currentAns, freq);
		}

		ans[index] = currentAns;
	}
}


void queryResults(int a[], int n, Query q[], int m)
{
	// Find block size
	block = (int)sqrt(n);

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

	int q = sizeof(queries) / sizeof(queries[0]);

	queryResults(A, n, queries, q);

	return 0;
}