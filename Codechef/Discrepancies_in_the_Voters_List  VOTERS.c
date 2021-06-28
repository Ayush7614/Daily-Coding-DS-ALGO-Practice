#include <stdio.h>

int main(void)
{
    int n1,n2,n3;//n1,n2,n3 are the number of ids in respective lists
    scanf("%d%d%d",&n1,&n2,&n3);
    int total=n1+n2+n3;//total number of input we have to take

    int max=0;//will take the largest number from all three lists

    int arr[10000000]={0};//this tracks how many times a number is repeated

/*even though range of n1,n2,n3 is 50000 but the incorrect id can be of greater number so to avoid
SIGSEGV in codechef we define a larger range*/
    for(int i=0;i<total;i++)
    {
        int temp;
        scanf("%d",&temp);//taking input
        arr[temp-1]++;//increasing if number is found
        if(temp>max)
        {
            max=temp;
        }
    }
    int count=0;//counts total number of ids that will be present in the final list

    for(int i=0;i<max;i++)//this loop just counts the id that are repeated more than once
    {
        if(arr[i]>=2)
        {
            count++;
        }
    }
/*we could also have created an array to store the numbers
we get in the above if and hence avoided use of two for loops*/
    printf("%d\n",count);
     for(int i=0;i<max;i++)
    {
        if(arr[i]>=2)
        {
            printf("%d\n",i+1);//this prints the ids
        }
    }


	// your code goes here
	return 0;
}

/*
Test case:
1.
5 6 5
23
30
42
57
90
21 
23 
35 
57 
90 
92 
21 
23 
30 
57 
90 

Sample Output:
5
21 
23 
30 
57 
90

2.
3 4 4
1
2
3
1
2
3
4
1
2
3
5

Sample Output:
3
1
2
3

3.
4 5 6
20
21
23
24
19
20
21
22
23
19
20
21
22
23
24

Samle Output:
6
19
20
21
22
23
24


*/
