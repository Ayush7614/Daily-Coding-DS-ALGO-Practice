#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a[1000],n=1,i=0,result=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d ",&a[i]);
        result=result+a[i];
        }
    printf("%d",result);
        return 0;

}    
    

      
