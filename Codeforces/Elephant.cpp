#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll ans=0;
    
    ll x= n/5;
    ans+=x;
    n=n-(x*5);
    
    x=n/4;
    ans+=x;
    n-=(x*4);
    
    x=n/3;
    ans+=x;
    n-=(x*3);
    
    x=n/2;
    ans+=x;
    n-=(x*2);
    
    if(n==1)
    {
        ans++;
    }
    
    
    cout<<ans<<endl;
    
    
    
    
    
    return 0;
}