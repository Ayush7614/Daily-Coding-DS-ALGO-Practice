// Problem link Hackerrank: https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, d, i, j, temp;
    scanf("%d\t%d", &n, &d);
    
    int *arr = malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i= 0; i<d; i++)
    {
        temp = arr[0];
        for(j=0;j<n;j++)
        {
             arr[j]= arr[j+1];
        }
    arr[n-1]= temp;
    }
    
    for(i = 0; i<n; i++)
    {
       printf("%d\t", arr[i]);
    }
    return 0;
}


