#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n,i; 
    scanf("%d",&n);
    int *c = malloc(sizeof(int) * n);
    for(int ci = 0; ci < n; ci++){
       scanf("%d ",&c[ci]);
    }
    int j=0;
    for(i=0;i<n-1;)
    {
        if(c[i+2]==0)
        {
            i=i+2;
            j++;
        }
        else 
        {
            i=i+1;
            j++;
        } 
    }
    printf("%d\n",j);
    return 0;
}
