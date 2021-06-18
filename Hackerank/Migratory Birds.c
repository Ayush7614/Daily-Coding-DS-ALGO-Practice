#include <stdio.h>
int main() 
{
    int n,i,max,ans;
    scanf("%d", &n);
    int a[n],h[6]={0};
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        h[a[i]]++;
    }
    max=h[1];
    for(i = 2; i < 6; i++)
    {
        if(max<h[i])
        {
            max=h[i];
            ans=i;
        }
   }
   printf("%d",ans);
   return 0;
}
