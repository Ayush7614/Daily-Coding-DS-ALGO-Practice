#include <stdio.h>

int main()
{
	int num,temp=0;
	scanf("%d",&num);   //taking input
	int num2 = num;
	while(num>0)
	{
		temp = (temp*10) + (num%10);
		num = num/10;
	}
	
	if(temp==num2)
	{
		printf("%d is palindrome.\n",num2);
	}
	else
	{
		printf("%d is not palindrome.\n",num2);
	}
	
	
	return 0;
}

