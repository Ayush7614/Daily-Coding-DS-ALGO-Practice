//90 Kuriyama Mirai's Stones

/*

This is the solution of codeforces question Kuriyama Mirai's Stones, using segment tree.
The question code for this is 433 - B.

*/

#include<bits/stdc++.h>
using namespace std;
// A utility function to get the middle index from corner indexes. 
long long int getMid(long long int s, long long int e) 
{
	return s + (e -s)/2; 
} 

long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si) 
{ 
	// If segment of this node is a part of given range, then return 
	// the sum of the segment 
	if (qs <= ss && qe >= se) 
		return st[si]; 

	// If segment of this node is outside the given range 
	if (se < qs || ss > qe) 
		return 0; 

	// If a part of this segment overlaps with the given range 
	long long int mid = getMid(ss, se); 
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
		getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 

// Return sum of elements in range from index qs (quey start) 
// to qe (query end). It mainly uses getSumUtil() 
long long int getSum(long long int *st, long long int n, long long int qs, long long int qe) 
{ 
	// Check for erroneous input values 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		cout<<"Invalid Input"; 
		return -1; 
	} 

	return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 

// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si) 
{ 
	// If there is one element in array, store it in current node of 
	// segment tree and return 
	if (ss == se) 
	{ 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 

	// If there are more than one elements, then recur for left and 
	// right subtrees and store the sum of values in this node 
	long long int mid = getMid(ss, se); 
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + 
			constructSTUtil(arr, mid+1, se, st, si*2+2); 
	return st[si]; 
} 

/* Function to construct segment tree from given array. This function 
allocates memory for segment tree and calls constructSTUtil() to 
fill the allocated memory */
long long int *constructST(long long int arr[], long long int n) 
{ 
	// Allocate memory for the segment tree 

	//Height of segment tree 
	long long int x = (long long int)(ceil(log2(n))); 

	//Maximum size of segment tree 
	long long int max_size = 2*(long long int)pow(2, x) - 1; 

	// Allocate memory 
	long long int *st = new long long int[max_size]; 

	// Fill the allocated memory st 
	constructSTUtil(arr, 0, n-1, st, 0); 

	// Return the constructed segment tree 
	return st; 
} 
int main()
{
	ios::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long int n;
	cin>>n;
	long long int v[n];
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	long long int *st1 = constructST(v, n); 
	//int n1 = sizeof(st1)/sizeof(st1[0]);
	sort(v,v+n);
	long long int *st2 = constructST(v, n); 
	//int n2 = sizeof(st2)/sizeof(st2[0]);
//	for(int i=0;i<n1;i++)
//	{
//		cout<<st1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n2;i++)
//	{
//		cout<<st2[i]<<" ";
//	}
//	cout<<endl;
	long long int m;
	cin>>m;
	while(m--)
	{
		long long int type,l,r;
		cin>>type>>l>>r;
		l--;r--;
		if(type == 1)
		{
			long long int ans = getSum(st1, n, l, r);
			cout<<ans<<endl;
		}
		else
		{
			long long int ans = getSum(st2, n, l, r);
			cout<<ans<<endl;
		}
	}
    return 0;
}
