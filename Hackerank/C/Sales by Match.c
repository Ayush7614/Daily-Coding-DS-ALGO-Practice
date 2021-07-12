#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   int i,t,c,j,a[101];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<t;i++){
        for(j=i+1;j<t;j++){
            if(a[i]==a[j] && a[i]>0){
                c++;
                a[i]=0;
                a[j]=0;
            }
        }
    }
    printf("%d",c);
    return 0;
}
