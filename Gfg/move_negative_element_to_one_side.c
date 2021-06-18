#include<stdio.h>
struct Array{
    int *A;
    int size;
    int length;
};
void Display(struct Array *arr){
    int i;
    printf("Elements are\n");
    for(i=0;i<arr->length;i++){
        printf("%d ",arr->A[i]);
    }
}
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void rearrange(struct Array *arr)
{
    int j = 0;
    int i;
    for ( i = 0; i < arr->length; i++) {
        if (arr->A[i] < 0) {
            if (i != j)
                swap(&arr->A[i], &arr->A[j]);
            j++;
        }
    }
}
int main(){
    struct Array arr;
    printf("Enter size of an array\n");
    scanf("%d",&arr.size);
    printf("Enter length of an array\n");
    scanf("%d",&arr.length);
    printf("Enter elements\n");
    int i;
    for(i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }
    Display(&arr);
    rearrange(&arr);
    Display(&arr);
    return 0;
}