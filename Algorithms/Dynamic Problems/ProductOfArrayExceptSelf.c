#include <stdio.h>
#include <stdlib.h>

int* ProductOfArrayExceptSelf(int* a, int arr_count);

int main()
{
    int arr_size,i;
    printf("Number of elements in an array: ");
    scanf("%d",&arr_size);
    int* arr = malloc(arr_size*sizeof(int));

    printf("Enter the elements: ");

    for(i = 0; i < arr_size; i++)
        scanf("%d",&arr[i]);

    int* result = ProductOfArrayExceptSelf(arr,arr_size);

    for(i = 0; i < arr_size; i++)
        printf("%d ",result[i]);

    return 0;
}

int* ProductOfArrayExceptSelf(int* arr, int arr_count)
{
    int temp,i,product=1;
    int* right_transversal = malloc(arr_count*sizeof(int));
    int* left_transversal = malloc(arr_count*sizeof(int));
    int* result = malloc(arr_count*sizeof(int));

    for(i=0;i<arr_count;i++)
    {
        temp = arr[i];
        left_transversal[i] = product;
        product *= temp;
    }
    product = 1;
    for(i=arr_count-1; i >= 0;i--)
    {
        temp = arr[i];
        right_transversal[i] = product;
        product *= temp;
    }

    for(i=0;i<arr_count;i++)
        result[i] = right_transversal[i] * left_transversal[i];

    return result;
}


/* Algorithm that runs in O(n) time and without using the division operation.
Input: nums = [1,2,3,4]
Output: [24,12,8,6] */
