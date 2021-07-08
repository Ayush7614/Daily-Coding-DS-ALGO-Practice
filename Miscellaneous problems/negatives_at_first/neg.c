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
