#include <stdio.h>
#include <string.h>

int isoperand(char);
void push(char);
void display();

char s[25] = {'\0'};
int top = -1;
char ch;

//Driver Code
void main()
{
	char prefix[25] = {'\0'};
	char ele;
	int i, j;
	printf("\nEnter Prefix expression:");
	scanf("%s", prefix);
	i = strlen(prefix) - 1;
	while (i >= 0)
	{
		ele = prefix[i];
		if (isoperand(ele))
		{
			push(ele);
			push(' ');
			printf("\n ele = %c Push to Stack S", ele);
		}
		else
		{
			printf("\n operator = %c", ele);
			for (j = top - 1; j >= 0; j--)
			{
				if (s[j] == ' ')
				{
					s[j] = ele;
					break;
				}
			}
		}
		i--;
		display();
		printf("\n-------------------------------");
	}
	printf("\n Prefix = %s", prefix);
	printf("\n Infix expression = %s\n", strrev(s));
}

//User Defined Functions

int isoperand(char ele)
{
	if ((ele >= 'A' && ele <= 'Z') || (ele >= 'a' && ele <= 'z'))
		return 1;
	else
		return 0;
}

void push(char ele)
{
	if (top == 24)
		printf("\n Stack is Full");
	else
	{

		top++;
		s[top] = ele;
	}
}

void display()
{
	int i;
	for (i = 0; i <= top; i++)
		printf("\n s[%d] = %c", i, s[i]);
}