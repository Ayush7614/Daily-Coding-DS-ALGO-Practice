#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    float k1,k2,k3,v;
	    cin>>k1>>k2>>k3>>v;
	    float t = (k1*k2*k3*v);
	    float res = 100.00/t;
	    float a=9.575;
	    if(res<a)
	    cout<<"YES"<<endl;
	    else if(res>=a)
	    cout<<"NO"<<endl;
	    
	    
	}
	return 0;
}
