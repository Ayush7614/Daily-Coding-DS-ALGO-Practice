// Given an array A[] of size N and an integer diff, the task is to count the number of ways
//to split the array into two subsets (non-empty subset is possible)
// such that the difference between their sums is equal to diff

// Input: A[] = {1, 1, 2, 3}, diff = 1
// Output: 3
// Explanation: All possible combinations are as follows:
//
// {1, 1, 2} and {3}
// {1, 3} and {1, 2}
// {1, 2} and {1, 3}
// All partitions have difference between their sums equal to 1. Therefore, the count of ways is 3.

// Naive Approach: The simplest approach to solve the problem is based on the following observations:
//
// Let the sum of elements in the partition subsets S1 and S2 be sum1 and sum2 respectively.
// Let sum of the array A[] be X.
// Given, sum1 – sum2 = diff – (1)
// Also, sum1 + sum2 = X – (2)
//
// From equations (1) and (2),
// sum1 = (X + diff)/2

// Therefore, the task is reduced to finding the number of subsets with a given sum.
// Therefore, the simplest approach is to solve this problem is by generating all the possible subsets and checking whether the subset has the required sum.
//
// Time Complexity: O(2N)
// Auxiliary Space: O(N)
//
// Efficient Approach: To optimize the above approach, the idea is to use Dynamic Programming.
//Initialize a dp[][] table of size N*X, where dp[i][C] stores the number of subsets of the sub-array A[i…N-1] such that their sum is equal to C.
// Thus, the recurrence is very trivial as there are only two choices i.e. either consider the ith element in the subset or don’t.
// So the recurrence relation will be:
// dp[i][C] = dp[i – 1][C – A[i]] + dp[i-1][C]



// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to divide
// the array into two subsets and such that the
// difference between their sums is equal to diff
int countSubset(int arr[], int n, int diff)
{
    // Store the sum of the set S1
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    sum += diff;
    sum = sum / 2;

    // Initializing the matrix
    int t[n + 1][sum + 1];

    // Number of ways to get sum
    // using 0 elements is 0
    for (int j = 0; j <= sum; j++)
        t[0][j] = 0;

    // Number of ways to get sum 0
    // using i elements is 1
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    // Traverse the 2D array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {

            // If the value is greater
            // than the sum store the
            // value of previous state
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];

            else {
                t[i][j] = t[i - 1][j]
                          + t[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Return the result
    return t[n][sum];
}

// Driver Code
int main()
{
    // Given Input
    int diff = 1, n = 4;
    int arr[] = { 1, 1, 2, 3 };

    // Function Call
    cout << countSubset(arr, n, diff);
}


// Output:
// 3
// Time Complexity: O(S*N), where S = sum of array elements + K/2
// Auxiliary Space: O(S*N)
