#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	ll p,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>p>>a>>b>>c;
		cout<<min(min((a-p%a)%a,(b-p%b)%b),(c-p%c)%c)<<"\n";
	}
	return 0;
 } 