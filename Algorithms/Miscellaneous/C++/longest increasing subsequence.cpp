//  LIS (Longest Increasing Subsequence) problem 
#include <iostream>
 using namespace std;
                                                        // lis() returns the length of the longest increasing
                                                                      //subsequence in arr[] of size n 
int lis(int arr[], int n)                                    //function definition
{
    int *lis, i, j, max = 0;
    lis = (int*)malloc(sizeof(int) * n);                               // Initialize LIS values for all indexes 
    for (i = 0; i < n; i++)
        lis[i] = 1;                                          // Compute optimized LIS values in bottom up manner 
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
   
    for (i = 0; i < n; i++)                                              // Pick maximum of all LIS values 
        if (max < lis[i])
            max = lis[i];
 
   
    free(lis);                                                          // Free memory to avoid memory leak 
 
    return max;
}
 
int main()                                                            // Driver program to test above function 
{                                                                     //function decleartion
    int arr[] = { 15, 27, 14, 38, 26, 55, 46, 65 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
    return 0;
}
