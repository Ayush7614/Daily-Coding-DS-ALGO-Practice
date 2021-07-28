/*      STATEMENT :PRINT MATRIX OF SIZE N*N IN A SPIRAL FORMAT
AUTHOR : MOHIT KUMAR KUSHWAHA
GITHUB ID: KimtVak8143


EXAMPLE TEST CASE :
    INPUT:
    ENTER THE SIZE OF MATRIX :  5

    ENTER THE ROW 1 :   7 4 1 9 13
    ENTER THE ROW 2 :   16 14 8 21 6
    ENTER THE ROW 3 :   31 2 5 19 10
    ENTER THE ROW 4 :   41 50 44 49 40
    ENTER THE ROW 5 :   38 36 39 35 34

    OUTPUT :
    The resultant spiral form is :
    7 4 1 9 13 6 10 40 34 35 39 36 38 41 31 16 14 8 21 19 49 44 50 2 5


*/
#include<stdio.h>
int main()
{   int n,i,j,r,c;
    printf("ENTER THE SIZE OF MATRIX :\t");
    scanf("%d",&n);
    int spiral[n][n];
    for(i=0;i<n;i++)
    {   printf("\nENTER THE ROW : %d\t",i+1);
        for(j=0;j<n;j++)
            scanf("%d",&spiral[i][j]);
    }
    int rstart=0,rend=n-1;
    int cstart=0,cend=n-1;
    printf("\nThe resultant spiral form is :\n");
    while(rstart<=rend)
    {   for(c=cstart; c<=cend;c++)
            printf("%d ",spiral[rstart][c]);
        rstart++;
        for(r=rstart;r<=rend;r++)
            printf("%d ",spiral[r][cend]);
        cend--;
        for(c=cend; c>=cstart;c--)
            printf("%d ",spiral[rend][c]);
        rend--;
        for(r=rend; r>=rstart; r--)
            printf("%d ",spiral[r][cstart]);
        cstart++;
    }
    return 0;
}
