#include<stdio.h>
void main()
{
    int ar[10],br[10],n1,n2,temp,i=0,j=0,c1=0,c2=0,count=0,s1=0,s2=0;
    printf("enter first no:\n");
    scanf("%d",&n1);
    printf("enter second mo:\n");
    scanf("%d",&n2);
    while(n1!=0)
    {
        temp=n1%10;
        ar[i]=temp;
        i++;
        n1=n1/10;
        c1++;
    }
    while(n2!=0)
    {
        temp=n2%10;
        br[j]=temp;
        j++;
        n2=n2/10;
        c2++;
    }
    int key;
    i=1;j=0;
    while(i<c1)
    {
        key=ar[i];
        j=i-1;
        while(j>=0&&ar[j]>key)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
        i++;
    }
    i=1;j=0;
    while(i<c2)
    {
        key=br[i];
        j=i-1;
        while(j>=0&&br[j]>key)
        {
            br[j+1]=br[j];
            j--;
        }
        br[j+1]=key;
        i++;
    }
    for(i=0;i<c1;i++)
    {
        printf("%d",ar[i]);
    }
    printf("\n");
     for(i=0;i<c2;i++)
    {
        printf("%d",br[i]);
    }
    for(i=0;i<c1;i++)
    {
        if(ar[i]==br[i])
        {
            s1+=ar[i];
            count++;
        }
        else 
        {
            s2=s2+ar[i]+br[i];
        }
    }
    if(count==c1)
    {
        printf("\nsum of digits:%d",s1);
    }
    else
    {
        printf("\nsum of different digits:%d",s2);
    }
}