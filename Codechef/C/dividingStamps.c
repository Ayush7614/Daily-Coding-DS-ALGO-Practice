#include <stdio.h>
/*The question basically wants us to calculate if the total number of stamps
is equal to the sum of all natural numbers upto n*/
int main(void) {
	// your code goes here
	long int n;
	scanf("%lld",&n);
	long long int count=0;

	for(long long int i=0;i<n;i++)
	{
	    long long int temp;
	    scanf("%lld",&temp);
	    count=count+temp;
	}
  //After loop ends the count variable will contain the total number of stamps

	long long int cal=n*(n+1)/2;//formula to calculate sum of n natural numbers
	if(cal==count)
	{
	    printf("YES\n");
	}
	else
	{
	    printf("NO\n");
	}
	return 0;
}


/*
TEST CASES:

Input:
5
7 4 1 1 2

Output:
YES

Input:
5
1 1 1 1 1

Output:
NO





*/
