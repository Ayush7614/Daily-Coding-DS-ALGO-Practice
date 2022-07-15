/*
This problem basically focuses on the use of Dynamic Programming in solving the below question:-

Q: Given an array of elements give out the length largest possible subset consisting of elements where the larger elemnts
	are divisible by the smaller elements.

*/


#include<bits/stdc++.h>

using namespace std;

int largestSubset(int a[],int n) {		//calling the largestSubset function

	sort(a,a+n);	//sorting the array first


	int dp[n];		// declaring an array to store the result for every elemnent from the array 
					//and then comparing the largest element


	dp[n-1]=1;		//initialsing the size for() the largest array element as 1.

	for(int i=n-2;i>=0;i--) {
		int m=0;				//initialising the count of elements for every array element greater then it but also divisible by it
		for(int j=i+1;j<n;j++) {
			if(a[j]%a[i]==0) {	// travresing all the elements greater than the current element
				m=max(m,dp[j]);	//if the condition is satisfied, we compare the count of the subset at the greater element and the cuurent value of m, and use the greater one
			}
		} 
		dp[i]=m+1;	//we add 1 to the count, because we include the element itself also.
	}

	return *max_element(dp,dp+n); //atlast we return the largest element in the dp array.

}


int main() {


int n;		//declaring the size of the array
cin>>n;

int a[n];	//declaring the array

for(int i=0;i<n;i++) {
	cin>>a[i];				//input of the array elements
}

int h=largestSubset(a,n);	// calling the largestSubset function


cout<<h<<endl;	//returning the result of the function

	return 0;
}

