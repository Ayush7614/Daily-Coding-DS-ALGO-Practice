#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool DuplicateElement(int* arr,int arr_size);

int main()
{
    int size,i;

    printf("The number of elements in the array: ");
    scanf("%d",&size);

    int* arr = malloc(size*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<size;i++)
       scanf("%d",&arr[i]);

    if(DuplicateElement(arr,size) == true)
        printf("True");
    else
        printf("False");

    return 0;
}

bool DuplicateElement(int* arr,int arr_size)
{
    int i,j;
    for(i=0;i<arr_size;i++)
    {
        for(j=i+1;j<arr_size;j++)
        {
            if(arr[i] == arr[j])
               return true;
        }
    }
    return false;
}

/*
Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.
Input: nums = [1,2,3,1]
Output: true
*/
