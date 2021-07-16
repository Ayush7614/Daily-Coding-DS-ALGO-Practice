/* C program to find union of two sorted arrays
 
 Example:
 Input:
 arr1[] = { 1, 2, 4, 5, 8,9 }
 arr2[] = { 2, 3, 5, 6,10 }
 Output: Union : {1,2,3,4,5,6,8,9,10}  
*/
#include <stdio.h>
 void UnionArray(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            printf(" %d ", arr1[i++]);
        else if (arr2[j] < arr1[i])
            printf(" %d ", arr2[j++]);
        else {
            printf(" %d ", arr2[j++]);
            i++;
        }
    }
 
    /* Print remaining elements of the larger array */
    while (i < m)
        printf(" %d ", arr1[i++]);
    while (j < n)
        printf(" %d ", arr2[j++]);
}
 
int main()
{
    int arr1[] = { 1, 2, 4, 5, 8,9 };
    int arr2[] = { 2, 3, 5, 6,10 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    UnionArray(arr1, arr2, size1, size2);
    return 0;
}