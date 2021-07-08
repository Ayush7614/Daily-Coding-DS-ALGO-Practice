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

