// Given an array and an integer k find the maximum sum of k consecutive elements.

// Solution
#include<bits/stdc++.h>
using namespace std;

// Print Fucntion
void print(int arr[], int i, int j)
{
    printf("{");
    for (int m=i; m<=j; m++)
    {
        printf("%d ", arr[m]);
    }
    printf("}\n");
}

// SubArray Fucntion
void SubArray(int arr[], int n, int sum)
{
    for(int i=0; i<n; i++)
    {
        int currSum = 0;
        for(int j=i; j<n; j++)
        {
            currSum = currSum+arr[j];
            if(currSum==sum)
            {
                print(arr, i, j);
            }
        }
    }
}

// Main Fucntion
int main()
{
    // Number of elements in array
    int n;
    cin>>n;
    
    // arr[n] array
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    // Sum
    int sum;
    cin>>sum;
    
    // Passing to the function
    SubArray(arr, n, sum);
    return 0;
}


// Test Cases
/*
Example 1:
Input:
3
1
1
2
2

Output:
{1 1 }
{2 }
*/
