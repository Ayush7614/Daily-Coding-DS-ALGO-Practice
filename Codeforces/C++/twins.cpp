#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
		int a[n];
		int i,j,sum=0,c=0;
		for(j=0;j<n;j++)
		cin>>a[i];
		sort(a,a+n); //sorting the array in ascending order
		for(i=0;i<n;i++)
		{
		    if(sum<=a[i])
		   { sum+=a[i];
		     c++;
		   }  
		}
		cout<<c;
		return 0;
}
