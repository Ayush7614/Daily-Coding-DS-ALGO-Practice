/*
Maximize the sum of selected numbers from an array to make it empty.

Given a sorted array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists), and Ai each from the array. Repeat these steps until the array gets empty. The problem is to maximize the sum of the selected numbers.

Example:
Input : arr[ ] = {1, 2, 3}
Output :  4

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
Note: Numbers need to be selected from maximum to minimum.
*/

#include <bits/stdc++.h>

using namespace std;

// function to maximize the sum of selected numbers
int maximizeSum(int arr[], int n)
{

    // Largest element in the array
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }

    // An array to count the occurrence of each element
    int freq[mx + 1];

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // ans to store the result
    int ans = 0, i = mx;

    // Using the above mentioned approach
    while (i > 0)
    {

        // if occurrence is greater than 0
        if (freq[i] > 0)
        {
            // add it to ans
            ans += i;

            // decrease i-1th element by 1
            freq[i - 1]--;

            // decrease ith element by 1
            freq[i]--;
        }
        else
        {
            // decrease i
            i--;
        }
    }

    return ans;
}

// Driver code
int main()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maximizeSum(a, n);
    return 0;
}
