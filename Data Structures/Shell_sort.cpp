#include<iostream>
using namespace std;
void ShellSort(int a[], int n)		// A function implementing Shell sort. 
{
	int i, j, k, temp;

	// Gap 'i' between index of the element to be compared, initially n/2. 
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++) 
		{
			for(k = j-i; k >= 0; k = k-i) 
			{ 
				if(a[k+i] >= a[k])		// If value at higher index is greater,
					break;				// then break the loop.
				else
				{
					temp = a[k];		//swapping the elements to sort the data
					a[k] = a[k+i];
					a[k+i] = temp; 
				}
			} 
		}
	}
}

int main() 
{
	int n, i;
	cout<<"\nEnter the number of elements to be sorted: "; 
	cin>>n;
	int arr[n];
	for(i = 0; i < n; i++)		//TAKING THE INPUT DATA
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i]; 
	}
	cout<<"\nGiven Data: ";
	for (i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<"\n\n";
	ShellSort(arr, n); 
	cout<<"\nSorted Data: "; 		//DISPLAYING THE SORTED DATA
	for (i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<"\n\n"; 
	return 0;
}