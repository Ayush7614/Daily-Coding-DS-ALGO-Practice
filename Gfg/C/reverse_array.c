//print the array in reverse order 
#include <stdio.h>
int main()
{
    int n,i,a[100];

    printf("Enter the size of array:");
    scanf("%d",&n);

    for (i=0 ; i<n ; i++)
    {
        printf("Enter a[%d]:",i);    //for inputting array 
        scanf("%d",&a[i]);
    }
    printf("The original array:");
    for(i=0 ; i<n ; i++)            //print original array
    {
        printf("%d \t",a[i]);
    }
    printf(" \nThe reverse array is : ");
    for (i=n-1 ; i>=0 ;i--)
    {
        printf("%d \t",a[i]);
    }

    return 0;
}