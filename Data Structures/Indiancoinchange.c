#include<stdio.h>
#define max 100
int ans[max];
int findMinCoins(int den[], int size,  int value)
{
    int i, count = 0;
    for(i = 0; i < size; i++)
    {
        while(value >= den[i])
        {
            value -= den[i];
            ans[count] = den[i];
            count++;
        }
        if(value == 0)
            break;
    }
    return count;
}
int main()
{
    int den[] = {25,20,10,5};
    int value,i;
    printf("Enter value\n");
    scanf("%d",&value);
    int size = sizeof(den)/sizeof(den[0]);
    int Mincount = findMinCoins(den,size,value);
    printf("Total Coins Needed = %d\n",Mincount);
    printf("Coins are:\t");
    for(i = 0; i < Mincount; i++)
        printf("%d ", ans[i]);
    return 0;
}
/* 
Testcase 1:
Input: Enter value:105
Output: 
Total Coins Needed = 5
Coins are:	25 25 25 25 5 

Testcase 2:
Input: Enter value :40
Output:
Total Coins Needed = 3
Coins are:	25 10 5 
*/