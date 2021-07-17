#include <stdio.h>
 
//Function to swap elements A[i] and A[j] in an array
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
// Linear time partition function to sort an array containing 0, 1, and 2
int Sort_zero_one_two(int A[], int end)
{
    int start = 0, mid = 0;
    int pivot = 1;
 
    while (mid <= end)
    {
        if (A[mid] < pivot) // current element is 0
        {
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] > pivot) // current element is 2
        {
            swap(A, mid, end);
            --end;
        }
        else { // current element is 1
            ++mid;
        }
    }
}
 
int main()
{
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter the elements of the array (0s 1s 2s)\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
 
    Sort_zero_one_two(arr, n - 1);
    
    printf("The sorted array of is: \n");
    // Prints the sorted array
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
/*
Input:
8
0 1 2 0 1 2 0 1

Output:
0 0 0 1 1 1 2 2
*/

/*
Time Complexity: O(n). 
Space Complexity: O(1). 
*/
