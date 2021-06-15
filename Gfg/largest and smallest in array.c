#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n); //array size
	int arr[n];
	int i;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]); //input array values
	}
	int largest = arr[0];
	int smallest = arr[0];
	for(i=0 ; i<n ; i++)
	{
		if(arr[i]>largest)
		{
			largest = arr[i];
		}
		if(arr[i]<smallest)
		{
			smallest = arr[i];
		}
	}
	
	printf("Largest number: %d \n",largest);
	printf("Smallest number: %d \n",smallest);
	
	
	return 0;
}

