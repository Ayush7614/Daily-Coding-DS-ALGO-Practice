#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	 
	  long int n;
	  cin>>n;
	  int s=0,m=1;
	  while(n>=s)
	  {
	      s=pow(2,m);
	      m++;
	  }
	 long int a=pow(2,m-2)-1;
	 long int sum=s-n;
	 long int ans=a*(a+sum);
	 cout<<ans<<endl;
	    
	}   
	return 0;
}
