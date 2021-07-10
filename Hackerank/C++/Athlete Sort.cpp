#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cin>>arr[i][j];
		}
	}

	int k;
	cin>>k;

	int temp;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n-i-1 ; j++)
		{
			if(arr[j][k] > arr[j+1][k])
			{
				for(int l=0 ; l<m ; l++)
				{
					temp = arr[j][l];
					arr[j][l] = arr[j+1][l];
					arr[j+1][l] = temp;
				}
			}
		}
	}

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}

