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
    ll n,m;
    cin>>n>>m;
    ll arr[m];
    loop(i,1,m+1)
        cin>>arr[i];
    arr[0]=1;    
    ll ans = 0;
    
    for(int i=1;i<=m;i++)
    {
        if(arr[i]>=arr[i-1])
           ans+=arr[i]-arr[i-1];
        else
            ans += n+arr[i]-arr[i-1];
    }
    
    cout<<ans<<endl;
    
    
    
    return 0;
}