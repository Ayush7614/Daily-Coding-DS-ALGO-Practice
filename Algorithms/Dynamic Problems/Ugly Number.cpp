/* Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
Given a number n, the task is to find n’th Ugly number.

*/

// CPP program to find nth ugly number
#include <stdio.h>
#include <stdlib.h>

// This function divides a by greatest divisible
// power of b
int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;
	return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
	
	int i = 1;
	
	// ugly number count
	int count = 1;

	// Check for all integers untill ugly count
	// becomes n
	while (n > count) {
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}

// Driver Code
int main()
{
	// Function call
	unsigned no = getNthUglyNo(150);
	printf("150th ugly no. is %d ", no);
	getchar();
	return 0;
}
