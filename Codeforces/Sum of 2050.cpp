#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        
        
            if(n%2050!=0)
            printf("-1\n");
            else
            {
            ll ans=0;
            ll div=n/2050;
            while(div>0)
            {
                ans+=div%10;
                div=div/10;
            }
            
            printf("%lld\n",ans);
            
            }
        
        
        
        
    }
    
    
    
    return 0;
}