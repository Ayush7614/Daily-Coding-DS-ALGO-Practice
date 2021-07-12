#include <stdio.h>

int main(void) {
	long long t;//Inputting the total testcases
	scanf("%lld",&t);
	while(t--!=0)
	{
	    long long x1,x2,y1,y2,z1,z2;
	    scanf("%lld %lld %lld %lld %lld %lld",&x1,&x2,&y1,&y2,&z1,&z2);
	    if(x2>=x1 && y2>=y1 && z2<=z1)//Checking the condition
	     printf("YES\n");
	    else
	    printf("NO\n");
	}
	return 0;
}

/*
Input-
4
20 50 2100 1900 6 6
50 20 1900 1900 5 5
20 20 1900 1900 1 6
27 27 1920 1920 3 3
Output-
NO
NO
NO
YES
*/
