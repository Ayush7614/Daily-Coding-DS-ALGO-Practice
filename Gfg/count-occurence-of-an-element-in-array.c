// 7)	 Given	an	number	n.	Find	the	number	of	occurrences	of	n	in	the	array
#include<stdio.h>
struct Array
{
int *A;
int size;
int length;
};
void occurence(struct Array arr,int num){
    int i;
    int count=0;
    for(i=0;i<arr.length;i++)
    {
         if(num==arr.A[i]){
            count++;
         }
        
    }
    printf("the number %d is repeated %d times",count,num);

}

int main()
{
    struct Array arr;
    printf("Enter size of an array\n");
    scanf("%d",&arr.size);
    printf("Enter length of an array\n");
    scanf("%d",&arr.length);
    printf("Enter 10 elements\n");
    int i;
    int num;
    for(i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }
   printf("enter number to find the occurence");
   scanf("%d",&num);
occurence(arr,num);

}