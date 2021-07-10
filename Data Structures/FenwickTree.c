/*
CODE DESCRIPTION:
The following program implements fenwick tree .They are used to implement the arithmetic coding algorithm. 
It is an efficient data structure for finding and manipulation of the prefix sum (cumulative sum) of a sequence of numbers. 
Also called as Binary Indexed Tree.
*/

#include <stdio.h>

int FWtree[100] = {0};
int SIZE;

/* Function to get sum of all numbers in the array */
int get_sum(int i)
{
	int sum = FWtree[i];
	while(i)
	{
		/*Partial Sum is stored In Fenwick Tree array */
		i -= (i & (-i));
		sum += FWtree[i];
	}
	return sum;
}
/* Function to update the value at given i index */
void add(int i, int value)
{
	while(i < SIZE)
	{
		FWtree[i] += value;
		//Isolating the last set bit 
		i += (i & (-i));
	}
}
/* Function to implement the Fenwick Tree */
void init_fw_tree(int my_array[], int start, int end)
{
	SIZE = end-start+2;
	int i;
	//Storing values in Fenwick Tree
	for(i = 1; i <= end-start+2; i++)
	{
		add(i, my_array[ start+i-1 ]);
	}
}

int main()
{	

	int my_array[30];
	int i,n,val,index;
	
	printf("Enter size of array : ");
	scanf("%d",&n);
	
	printf("Enter input for array :-- \n");
	for (i=1;i<=n;i++)
	{
		scanf("%d",&my_array[i]);
	}
	
	init_fw_tree(my_array,1,n);

	printf("Sum of all  numbers in the array is = %d\n",get_sum(n));
	
	printf("Enter the index followed by the value you want to be added :- \n");
	scanf("%d",&index);
	printf("Enter value:" );
	scanf("%d",&val);
	add(index,val);
	
	printf("New sum after updation is : %d",get_sum(n));

	return 0;
}
/*
COMPLEXITY:
Space Complexity: O(N) for declaring another array of size N

Time Complexity: O(logN) for each operation

OUTPUT:
Enter size of array : 5
Enter input for array :--
1
2
5
5
7
Sum of all  numbers in the array is = 20
Enter the index followed by the value you want to be added :-
4
Enter value:5
New sum after updation is : 25
*/
