#include<stdio.h>
#define MAX 100000

int main(void)
{
    int arr[MAX],i,n,d;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[(i+d)%n]);
    }
}
