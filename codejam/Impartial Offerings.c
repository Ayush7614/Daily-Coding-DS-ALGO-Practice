#include<stdio.h>
void main()
{
    int t;//number of test cases
    scanf("%d",&t);

    int temp2=1;//tracking the testcase
    while(t--)
    {
        int n;//number of pets
        scanf("%d",&n);
        int temp;
        int sz[100]={0};//this array tracks the number of pets with each size
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            sz[temp-1]=sz[temp-1]+1;//incrementing the value of index according to size found
        }
        long ans=0;//this will store our answer
        long incre=1;//this indicates number of treats for the pet of particular size

        for(int i=0;i<100;i++)
        {
	    /*The first pet size found with non-zero will be smallest among the pets
	      hence gets 1 and accordingly the number increases*/
            if(sz[i]!=0)
            {
                ans=ans+sz[i]*incre;
                incre++;
            }
        }
        printf("Case #%d: %ld\n",temp2,ans);//printing the output
        temp2++;
    }
}

/*
Test cases:
3
4
10 20 10 25
5
7 7 7 7 7
2
100 1

Sample output:
Case #1: 7
Case #2: 5
Case #3: 3



*/
