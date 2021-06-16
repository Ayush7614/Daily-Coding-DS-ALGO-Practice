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
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans = n-max(a+1,n-b)+1;
    cout<<ans<<endl;
    
    
    return 0;
}