#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5; 

int n,t,a[maxn],p[maxn];

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1];
		if(a[i]>a[p[i]]) p[i]=i;
	}
	for(int i=n;i;i--)
	{
		for(int j=p[i];j<=i;j++)
		{
			cout<<a[j]<<" ";
		}
		i=p[i];
	}
	cout<<"\n";
}
int main()
{
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}