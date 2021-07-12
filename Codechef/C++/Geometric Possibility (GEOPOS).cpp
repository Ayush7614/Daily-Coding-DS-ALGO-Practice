#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n ;
	    int a[n];
	    int sum=0 , maxNew=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum +=a[i];
	        maxNew=max(maxNew , a[i]);
	    }
	    if((sum - maxNew) > maxNew)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	    
	    
	    
	}
	return 0;
}
