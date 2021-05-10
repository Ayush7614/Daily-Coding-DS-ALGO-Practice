#include <stdio.h>
 
// Naive method to find a pair in an array with a given sum
void findPair(int arr[], int n, int sum)
{
    // consider each element except the last
    for (int i = 0; i < n - 1; i++)
    {
        // start from the i'th element until the last element
        for (int j = i + 1; j < n; j++)
        {
            // if the desired sum is found, print it
            if (arr[i] + arr[j] == sum)
            {
                printf("Pair found (%d, %d)", arr[i], arr[j]);
                return;
            }
        }
    }
 
    // we reach here if the pair is not found
    printf("Pair not found");
}
 
int main(void)
{
    int arr[] = { 8, 7, 2, 5, 3, 1 };
    int sum = 10;
 
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findPair(arr, n, sum);
 
    return 0;
}


