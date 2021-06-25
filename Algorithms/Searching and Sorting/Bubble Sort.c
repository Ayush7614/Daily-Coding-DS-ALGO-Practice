#include <stdio.h>

void bubbleSort(int arr[], int n)
{
	int i,j,temp;
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n-i-1 ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i=0 ; i<n ; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int n;
	scanf("%d",&n); // array size

	int arr[n];
	int i;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr, n);

	return 0;
}
