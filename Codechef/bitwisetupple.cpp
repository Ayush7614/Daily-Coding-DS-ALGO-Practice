//question problem https://www.codechef.com/JUNE21C/problems/BITTUP


#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll p = 1000000000 + 7;


int power(ll a, ll b)

{
	int res=1;
	a=a%p;
	while (b>0)
	{
		/* code */
		if(b%2!=0)
		res =(res*a)%p;

		b=b/2;
		a=(a*a)%p;

	}
	return res;

}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll k=power(2,n);
		//cout<<k;
		ll j= power((k-1),m);
		cout<<"\n"<<j;
		//int k=(2 to the power n -1)whole raise to the power to m;

	}
	return 0;
}



