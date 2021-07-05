#include<bits/stdc++.h>
using namespace std;

// 			Fixed Parities

// Link to the problem: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/fixed-parity-440254c0/

// Alice and Bob are playing a board game. They have n×n boards and two arrays a and b of length n. The value of each cell in the ith row and jth row is a[i]+b[j]. Alice asks q questions to Bob. In each question, Alice provides two cells A and B. She asks the following questions to Bob:
// Are there any paths from A to B that contains the same parity as A and B.
// Note: Bob can move from one cell to 8 neighbor cells in each step.

// Sample Input
// 3
// 0 3 1
// 1 5 3
// 2
// 2 1
// 3 3
// 3 1
// 1 3

// Sample Output
// YES
// NO

// Explanation
// In the first query, we can move from (2,1) to (2,2) then to (3,3).

// In the second query, the parity of two cells is different and therefore there isn't such a way.

int main()
{
	int n;
	cin>>n;

	int a[n],b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}

	int q;		//testcases
	cin>>q;
	while(q--)
	{
		int r1,c1;
		int r2,c2;

		cin>>r1>>c1;
		cin>>r2>>c2;

		int num1=a[r1]+b[c1];
		int num2=a[r2]+b[c2];

        if((num1%2==0 && num2%2==0) || (num1%2!=0 && num2%2!=0))
		{
			cout<<"YES"<<endl;
		}

        else
		{
			cout<<"NO"<<endl;
		}
	}
    return 0;
}

// In this code if we check if the no. in a row and column is similar to the no, in other row and column so we print yes, otherwise no.
// Similarity if both the no. are even or odd