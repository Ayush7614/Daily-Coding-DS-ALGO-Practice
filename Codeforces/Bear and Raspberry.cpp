#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
    ll n,c;
    cin>>n>>c;
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    ll ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int buy=arr[i]-arr[i+1]-c;
            if(buy>ans)
                ans=buy;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}