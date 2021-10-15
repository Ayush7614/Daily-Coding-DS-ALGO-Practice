#include <stdio.h>
struct poly
{
    int co;
    int ex;
};
void main()
{
    struct poly p1[10],p2[10],p[10];
    int n1,n2,i,j,k;
    printf("enter limit of polynomial 1:");
    scanf("%d",&n1);
    
    for(i=0;i<n1;i++)
    {   
        printf("enter co and ex: ");
        scanf("%d%d",&p1[i].co,&p1[i].ex);
        
    }
    printf("enter limit of polynomial 2:");
    scanf("%d",&n2);
    
    for(i=0;i<n2;i++)
    {
        printf("enter co and ex: ");
        scanf("%d%d",&p2[i].co,&p2[i].ex);
        
    }
    i=0,j=0,k=0;
    while(i<n1||j<n2)
    {
        if(p1[i].ex==p2[j].ex)
        {
            p[k].ex=p1[i].ex;
            p[k].co=p1[i].co+p2[j].co;
            i++,j++,k++;
        }
        else if(p1[i].ex>p2[j].ex)
        {
            p[k].ex=p1[i].ex;
            p[k].co=p1[i].co;
            i++,k++;
        }
        else
        {
            p[k].ex=p2[j].ex;
            p[k].co=p2[j].co;
            j++,k++;
        }
    }
    if(i<n1)
    {
        while(i<n1)
        {
            p[k].co=p1[i].co;
            p[k].ex=p1[i].ex;
            i++,k++;
        }
    }
    if(n1>n2)
    {
        for(k=0;k<n1;k++)
        {
            printf("co:%d  exp:%d\n",p[k].co,p[k].ex);
        }
    }
}