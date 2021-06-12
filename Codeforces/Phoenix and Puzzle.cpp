#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

bool kmain(double a)
{
	ll p = sqrt(a);

	if(p*p==a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int t;
	cin>>t; //testcases
	while(t--)
	{
		ll n;
		cin>>n; //number of puzzel pieces
		if(n%2!=0)
		{
			cout<<"NO"<<endl; //have to be even pices
		}
		else if(kmain(n/2) || (kmain(n/4) && n%4==0))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
