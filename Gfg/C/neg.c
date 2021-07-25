//Move All Negative numbers at the beginning
//Link of the problem: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
//Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5
// Note: Order of elements is not important here.
#include<stdio.h>
#include<stdlib.h>
int main(){
int size,i,j,temp,k;
printf("Enter the size of array:");
scanf("%d",&size);
int arr[size];
printf("Enter the elements of array:");
for(i=0;i<size;i++)
  scanf("%d",&arr[i]);
for(i=0;i<size-1;i++)
{ k=0;
    for(j=0;j<size-1;j++)
    {
        if(arr[j]>=0)
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            k++;
        }
    }
}
printf("Output:");
for(i=0;i<size;i++)
    printf("%d ",arr[i]);
return 0;
}
