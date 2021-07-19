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
}

//Test Cases
// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5

// Input: 1, 3, -5, -7, 8
// Output: -5, -7, 1, 3, 8

//Note: Order of numbers is not important here.
