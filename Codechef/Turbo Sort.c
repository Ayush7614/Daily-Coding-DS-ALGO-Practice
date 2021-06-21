#include <stdio.h>

int arr[1000000];
int main()
{
    int i,j,t;
    
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&j);
        arr[j]++;
    }
    for(i=0;i<1000000;i++)
    {
        if(arr[i] > 0)
        {
            while(arr[i]--)
            printf("%d\n",i);
        }
    }
	return 0;
}