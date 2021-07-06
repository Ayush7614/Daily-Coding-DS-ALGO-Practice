/*Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.*/

#include<stdio.h>
#include<stdlib.h>
int main(){
  int N,temp,i,j;
  printf("Enter the size of array:");
  scanf("%d",&N);
  int arr[N];
  printf("Enter the array containing 0,1 & 2 only:");
  for(i=0;i<N;i++)
  scanf("%d",&arr[i]);
  int k=0;
  for(i=0;i<2;i++)
  {
    for(j=0;j<N;j++)
    {
        if(arr[j]==i)
        {
            temp=arr[j];
            arr[j]=arr[k];
            arr[k]=temp;
            k++;
        }
    }
  }
  printf("Sorted Array:");
  for(i=0;i<N;i++)
    printf("%d",arr[i]);


return 0;
}
