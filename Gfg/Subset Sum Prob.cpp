//Question:
//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

//Example:

//Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
//Output: True
//There is a subset (4, 5) with sum 9.

#include <bits/stdc++.h>
#define MAX 10
using namespace std;

bool subsetSum(int arr[], int sum, int n){
	bool t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<sum+1;j++){
			if(i==0)
				t[i][j]=false;
			if(j==0)
				t[i][j]=true;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j)
				t[i][j]=(t[i-1][j-arr[i-1]]) || (t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
//	for (int i = 0; i <= n; i++){
//       for (int j = 0; j <= sum; j++)
//          cout<<t[i][j]<<"\t";
//       printf("\n");
	}
	return t[n][sum];
}

int main(){
	int arr[MAX], sum, n;
	cout<<"Enter the number of elements in the array: "<<endl;
	cin>>n;
	cout<<"Enter the elements of array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the sum: "<<endl;
	cin>>sum;
	if(subsetSum(arr,sum,n)==true)
	cout<<"True";
	else
	cout<<"False";
	return 0;
}
