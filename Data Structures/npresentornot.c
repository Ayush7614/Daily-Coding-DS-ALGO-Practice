// n is the number u want to check which would given by the user.
// Sample Input:
// 5
// 2
// 1 2 3 4 5
// Output : present/notpresent


//2) Check	whether	n	is	present	in	an	array	of	size	m	or	not.

#include<stdio.h>
struct Array
{
int *A;
int size;
int length;
};
void numpresent(struct Array arr,int num){
    int i;
    int flag;
    for(i=0;i<arr.length;i++)
    {
         if(num==arr.A[i]){
             flag=1;
             break;
         }
         else{
             flag=0;
         }
        
    }
    if(flag==1)
    {
        printf("present");
    }
    else{
        printf("not present");
    }
 
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
    printf("Enter the number u wan to check");
    scanf("%d",&num);
    numpresent(arr,num);
   
   

}