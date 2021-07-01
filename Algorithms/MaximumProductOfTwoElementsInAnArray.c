#include <stdio.h>
#include <stdlib.h>

int MaxProduct(int* nums, int numsSize);

int main()
{
    int arr_size;

    printf("The number of elements in the array: \n");
    scanf("%d",&arr_size);

    int* arr = malloc(arr_size * sizeof(int));

    printf("Enter the elements: ");
    for(int i = 0; i < arr_size; i++)
        scanf("%d",&arr[i]);
    
    int result = MaxProduct(arr, arr_size);
    printf("%d",result);

    return 0;
}

int MaxProduct(int* nums, int numsSize){

    int i;
    int num1 = nums[0];
    int num2 = num1;

    for(i=1;i<numsSize;i++)
    {
        if(nums[i] > num1)
        {
            num2 = num1;
            num1 = nums[i];
        }
        else if(nums[i] > num2)
            num2 = nums[i];
    }

    return (num1 - 1)*(num2 - 1);
}

/*
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1) in o(n) time.
Input: nums = [3,4,5,2]
Output: 12 
*/
