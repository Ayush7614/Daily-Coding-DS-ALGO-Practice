//9)Find	the	range	of	the	array.	Range	means	the	difference
//	between	the	maximum	and	minimum	element	in	the	array
//maximum	and	minimum	element	in	the	array.	


// Range means the difference between the maximum and minimum element in the array.
// Sample Input: 6
// -1 -2 -3 4 5 6
// Sample Output: 7

#include<stdio.h>
struct Array
{
int *A;
int size;
int length;
};
void minmax(struct Array arr){
    int min=arr.A[0];
    int max=arr.A[0];
    int i;
    for(i=0;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
        else if(arr.A[i]>max){
            max=arr.A[i];
        }
        
    }
    printf(" range is%d ",max-min);
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
    for(i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
    {
    printf("%d",arr.A[i]);
    }
    minmax(arr);    


}