//  Problem Link - https://www.codechef.com/LTIME96C/problems/NUMCOMP1

// Prerequisite- sieve of eratosthenes, prefix sum;
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

#define loopforward(i,a,b) for(ll i=a;i<b;i++)
#define loopbackward(i,b,a) for(ll i=b;i>a;i--)
#define TC ll t;cin>>t;while(t--) 
#define ff first
#define ss second
const ll N=1e7;
ll prime[N];
ll spf[N];
ll presum[N];
using namespace std;

void seive_prime()
{
	prime[N]={0};
	presum[N]={0};
	ll k=0;
	for(ll i=2;i<=1e7;i++)
	{	
		if(!prime[i]){
			k++;
			for(ll j=i*i;j<=1e7;j+=i){
				prime[j]=1;
				}
		}

        // Calculating The Presum  
		presum[i]=k;
	}
	
}
int main()
{
	fast_io
	
	seive_prime();
	TC{
		ll n;cin>>n;
		ll cnt=0;
		
		cnt+=presum[n]-presum[n/2];
	
		if(n>3) cnt++;
		cout<<cnt<<"\n";
	}
	
}