// A dynamic programming approach 
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b; // ternary operator
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom-u-manner
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

// Driver Code
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int value[n];
	int wt[n];
	int W ;
	cout<<"Enter your value: ";
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	cout<<endl;
	cout<<"Enter your weights: ";
		for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<endl;
	cout<<"Enter Weight capacity: ";
	cin>>W;
	cout <<"Knapsack value is: " <<knapSack(W, wt, value, n)<<endl;
	
	return 0;
}

/*
INPUT:
value[]={ 50, 90, 120 }
weights[]={ 10, 10, 40 }
w=50
OUTPUT:
220
*/
