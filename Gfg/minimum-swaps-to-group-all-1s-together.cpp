//Given an array of 0’s and 1’s, we need to write a program to find the minimum number of swaps required to group all 1’s present in the array together.
/*Input : arr[] = {1, 0, 1, 0, 1, 1}
Output : 1*/

#include <bits/stdc++.h>
using namespace std;

// Function to find minimum swaps to group all 1's together
int minSwaps(int arr[],int n){
int no_of1s = 0;
// find total number of all 1's in the array
for(int i=0;i<n;i++){
	if(arr[i] == 1)
	no_of1s++;
}
// length of subarray to check for
int x=no_of1s;
int count_of_1s=0;
int maxOnes;
// Find 1's for first subarray of length x
for(int i=0;i<x;i++){
	if(arr[i] == 1)
	count_of_1s++;
}
maxOnes=count_of_1s;
// using sliding window technique to find max number of ones in subarray of length x
for(int i=1;i<=n-x;i++) {
// first remove leading element and check if it is equal to 1 then decreament the value of count_of_1s by 1
if (arr[i-1] == 1)
	count_of_1s--;
// Now add trailing element and check if it is equal to 1 Then increment the value of count_of_1s by 1
if(arr[i+x-1] == 1)
	count_of_1s++;
if (maxOnes<count_of_1s)
	maxOnes=count_of_1s;
}

// calculate number of zeros in subarray of length x with maximum number of 1's
int no_of_0s = x-maxOnes;
return no_of_0s;
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
cout<<minSwaps(arr, n);
return 0;
}
