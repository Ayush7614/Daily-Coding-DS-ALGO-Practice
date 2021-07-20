/*      WELCOME 

THIS IS A C PROGRAM TO PRINT MULTIPLICATION TABLE OF ANY INTEGER.

SAMPLE TEST CASES :
#1   INPUT :

    Enter the number of test cases :        1

    Enter the Number :      8

    OUTPUT :

    8 * 1 = 8
    8 * 2 = 16
    8 * 3 = 24
    8 * 4 = 32
    8 * 5 = 40
    8 * 6 = 48
    8 * 7 = 56
    8 * 8 = 64
    8 * 9 = 72
    8 * 10 = 80

*/


#include<stdio.h>
int main()
{   int t,i;
    printf("\nEnter the number of test cases :\t");
    scanf("%d",&t);
    while(t--)
    {   int n;
        printf("\nEnter the Number :\t");
        scanf("%d",&n);
        for(i=1;i<11;i++)
        {   printf("\n%d * %d = %d",n,i,n*i);
        }

    }
    return 0;
}
