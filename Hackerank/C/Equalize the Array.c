#include<stdio.h>
int main()
{
    int n,i,j,k=0,x,y=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        x=a[i];
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
            k++;
        }
        if(y<k)
        {
            y=k;
        }
        k=0;
    }
    printf("%d",n-y);
}
