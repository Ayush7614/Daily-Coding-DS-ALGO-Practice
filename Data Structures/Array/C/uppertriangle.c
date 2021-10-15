#include <stdio.h>

int main()
{
    int p,q,i=0,j=0;
    int a[10][10];
    printf("enter 1st matrix row and col:\n");
    scanf("%d%d",&p,&q);
    printf("enter 1st matrix:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The entered matrix is:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            if(i!=j&&i<j)
            {
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}