#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	
	int a ,b,c;
	cin>>a>>b>>c;
	if((a>= 1 && a<=10) && (b>=1 && b<=10)  && (c>=1 && c<=10))
	{
	    if(a==b && b==c)
	    cout<<"YES"<<endl;
	    else if((a==b) && (a!=c) || ((a==c) && (a!=b)))
	    cout<<"YES"<<endl;
	    else if(a!=b &&  b!=c)
	    cout<<"NO"<<endl;
	    
	}
	return 0;
}
