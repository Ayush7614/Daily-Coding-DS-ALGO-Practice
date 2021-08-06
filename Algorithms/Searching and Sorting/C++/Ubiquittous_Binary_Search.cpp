#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int l, int r, int k)
{
	int m;

	while(r-l>1)
	{
		m = l+(r-l)/2;

		if(arr[m]<=k)
			l = m;
		else
			r = m;
	}

	if(arr[l] == k)
		return l;
	if(arr[r] == k)
		return r;
	else
		return 0;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
       cin>>a[i];
       
    int u;  // No u want to Search
    cin>>u;
    
    if(BinarySearch(a,0,n-1,u))
    cout<<"Number is Present";
    else
    cout<<"Number is not Present";
 }
/*
Input:
4
1 5 2 6
2
Output :- Number is Present
*/

/*
Time Complexity :- O(log(n))
*/
