#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int l = 2*n-1;
  for(int i=0;i<l;i++)
  {
    for(int j=0;j<l;j++)
    {
      int min = i<j? i:j;
      min=min<l-i? min:l-i-1;
      min=min<l-j? min:l-j-1;
      printf("%d ",n-min);
    }

    printf("\n");
  }
    return 0;
}
