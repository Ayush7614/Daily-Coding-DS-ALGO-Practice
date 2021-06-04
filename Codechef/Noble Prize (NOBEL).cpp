#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int newArr[m+1];
	    
	    for(int i=1;i<=m;i++)
	    {
	        newArr[i]=0;
	    }
	    for(int i=0;i<n;i++)
	    {
	        newArr[arr[i]]++;

	    }
	    bool flag=true;
	    for(int i=1;i<=m;i++)
	    {
	       if(newArr[i]==0)
	        {
	            flag=false;
	            cout<<"YES"<<endl;
	            break;
	        }
	    }
	    if(flag==true)
	        cout<<"NO"<<endl;
	}
	return 0;
}
