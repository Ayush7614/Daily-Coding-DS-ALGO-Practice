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
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans=0;
    int trip=0;
    while(trip<n)
    {
        if(b<=m*a && (n-trip)*a>b)
        {
                ans+=b;
                trip+=m;
        }
        else
        {
            trip++;
            ans+=a;
        }
        
    }
    cout<<ans<<endl;
    
    
    
    return 0;
}