/*
CODE DESCRIPTION:Ugly numbers are those numbers whose prime factors are 2, 3 or 5.
Following program finds out the n'th ugly number.
*/
#include <iostream>
using namespace std;

/* Function that divides a by greatest divisble power of b */
int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;
	return a;
}

/* Function to check if a number is ugly or not */
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);
	if(no==1)
	return 1;
	else
	return 0;
}

/* Function to get the nth ugly number */
int NthUglyNo(int n)
{
	int i = 1;
	/* To keep a count of the number of ugly number */
	int count = 1;
	/* Loop goes until count=Nth ugly number */
	while (n > count) {
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}

/* Driver Function */
int main()
{
	int num;
	cout<<"Enter the N'th ugly number you want  : ";
	cin>>num;
	int no = NthUglyNo(num);
	cout<<num<<"th Ugly Number is "<<no;
	getchar();
	return 0;
}
/*
COMPLEXITY:
Space : O(1)
Time :O(N)
OUTPUT:
Enter the N'th ugly number you want  : 150
150th Ugly Number is 5832
*/
