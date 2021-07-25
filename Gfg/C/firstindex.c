//Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
//Test Cases
//Input: Size:5 Array:4 5 6 7 4 Element:4
//Output: Index:0

//Input: Size:6 Array:1 2 3 3 4 3 Element:3
//Output: Index:2

#include<stdio.h>
#include<stdlib.h>
int first_index(int arr[],int size,int x,int k){
    if(k==size-1){
        return -1;
    }
   k++;
   if(arr[k]==x)
   {
       return k;
   }
   return first_index(arr,size,x,k);
}
int main(){
int N,x,i,index,k;
printf("Enter the size of array:");
scanf("%d",&N);
int arr[N];
printf("Enter the elements of array:");
for(i=0;i<N;i++)
  scanf("%d",&arr[i]);
printf("Enter the element for which you need the first index:");
scanf("%d",&x);
k=-1;
index = first_index(arr,N,x,k);
printf("Index is: %d",index);
return 0;

}

