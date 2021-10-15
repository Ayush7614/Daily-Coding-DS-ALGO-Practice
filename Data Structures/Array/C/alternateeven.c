#include <stdio.h>

int main()
{
   int flag=0;
   for(int i=2;i<25;i+=2)
   {
       if(flag==0)
       {
            flag=1;
            continue;
       }
       else
       {
            printf("%d ",i);
            flag=0;
       }
   }
    return 0;
}