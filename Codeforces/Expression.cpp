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
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=a+b+c;
    ans=max(ans,(a*b*c));
    ans=max(ans,((a+b)*c));
    ans=max(ans,(a*(b+c)));
    cout<<ans<<endl;
    
    
    return 0;
}