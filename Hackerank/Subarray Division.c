#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *squares = malloc(sizeof(int) * n);
    for(int squares_i = 0; squares_i < n; squares_i++)
    {
        scanf("%d",&squares[squares_i]);
    }
    int d;
    int m;
    scanf("%d %d",&d,&m);
    int count = 0;
    for (int i = 0;i <= n-m; ++i)
    {
        int sum = 0;
        for (int j = i;j < i+m; ++j)
        {
            sum += squares[j];
        }
        if (sum == d) 
        ++count;
    }
    printf("%d",count);
    return 0;
}
