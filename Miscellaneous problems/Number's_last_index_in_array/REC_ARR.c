#include<stdio.h>
#include<stdlib.h>

int last_index(int arr[],int size,int x){
    if(size<1){
        return -1;
    }
   size--;
   if(arr[size]==x)
   {
       return size;
   }
   return last_index(arr,size,x);
}
int main(){
int N,x,i,index;
printf("Enter the size of array:");
scanf("%d",&N);
int arr[N];
printf("Enter the elements of array:");
for(i=0;i<N;i++)
  scanf("%d",&arr[i]);

printf("Enter the element for which you need the last index:");
scanf("%d",&x);

index = last_index(arr,N,x);

printf("Index is: %d",index);

return 0;

}

