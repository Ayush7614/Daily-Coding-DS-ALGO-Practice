#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void arraySort(int *arr, int *n)
{
	int temp,j,i = 1;
	arr++;
	while(i<*n)
	{
		j=1;
		temp = *arr;
		while(temp<*(arr-j) && (i-j)>=0)
		{
			int k = *(arr-j);
			*(arr-j+1) = k;
			j++;
		}
		*(arr-j+1) = temp;
		i++;
		arr++;
	}
}

int main()
{
	int n;
	cout<<"Enter number of elements in array: ";
	cin>>n;

	int arr[n];
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>arr[i];
	}
	arraySort(&arr[0], &n);

	for(int i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
