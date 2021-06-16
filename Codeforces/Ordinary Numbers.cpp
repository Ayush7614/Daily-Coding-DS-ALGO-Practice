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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans =0;
        for(ll i =1;i<=n;i=i*10+1)
        {
            for(int j=1;j<=9;j++)
            {
                if(i*j<=n)
                    ans++;
            }
        }
        cout<<ans<<endl;
        
        
    }
    
    
    
    return 0;
}