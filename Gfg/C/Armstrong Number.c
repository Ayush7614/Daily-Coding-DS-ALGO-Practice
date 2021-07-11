#include <stdio.h>
#include <math.h>

int main()
{
	int num,temp=0;
	scanf("%d",&num);   //taking input
	int num2 = num;
	while(num>0)
	{
		temp = temp + pow((num%10),3);
		num = num/10;
	}
	
	if(temp==num2)
	{
		printf("%d is Armstrong.\n",num2);
	}
	else
	{
		printf("%d is not Armstrong.\n",num2);
	}
	
	
	return 0;
}

