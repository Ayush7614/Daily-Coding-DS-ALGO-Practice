#include <stdio.h>
int main ()
{
    int w;
    scanf("%d",&w); // number of watermelons
    if(w%2==0 && w!=2)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}