#include<stdio.h>
int main()
{   int t,i;
    printf("\nEnter the number of test cases :\t");
    scanf("%d",&t);
    while(t--)
    {   int n;
        printf("\nEnter the Number :\t");
        scanf("%d",&n);
        for(i=1;i<11;i++)
        {   printf("\n%d * %d = %d",n,i,n*i);
        }

    }
    return 0;
}
