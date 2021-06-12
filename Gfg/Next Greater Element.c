#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n); //Array size;
	int arr[n];
	int i;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]); //input values
	}
	int j,count=-1;
	for(i=0 ; i<n ; i++)
	{
		for(j=i+1 ; j<n ; j++)
		{
			if(arr[j]>arr[i])
			{
				printf("%d ",arr[j]);
				count++;
				break;
			}
		}
		if(count!=i)
		{
			printf("%d ",-1);
			count++;
		}
	}
	
	
	return 0;
}

