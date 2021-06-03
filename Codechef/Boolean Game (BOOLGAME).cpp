#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define DEBUG(x) cout<<'>'<<#x<<':'<<x<<endl
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
#define all(x) x.begin(),x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> g(n+1) ;
        REP(i,n){
            cin>>g[i+1];
        }
        vector<vector<pair<ll,ll>>> arr(n+1);
        REP(i,m){
            ll u,v,d;
            cin>>u>>v>>d;
            arr[u].pb(mp(i,d));
            arr[v].pb(mp(i,d));
        }
        vector<vector<pair<ll,ll>>> dp(n+1);
        dp[0].pb(mp(0,0));
        
        for(ll i=1;i<=n;i++)
        {
            vector<pair<ll,ll>> temp;
            temp.insert(temp.end(),all(dp[i-1]));
            ll curr=0,mask=0;
            set<ll> open;
            for(ll j=i;j>=1;j--)
            {
                curr+=g[j];
                mask^=1LL<<j;
                for(auto & [idx,w]:arr[j]){
                    if(open.count(idx)){
                        curr+=w;
                    }
                    else
                    {
                        open.insert(idx);
                    }
                }
                if(j>1){
                    for(auto & [val,old_mask]:dp[j-2]){
                        temp.pb(mp(val+curr,mask^old_mask));
                    }
                }
                else{
                    temp.pb(mp(curr,mask));
                }
                
            }
            sort(all(temp));
            reverse(all(temp));
            set<ll> sel;
            ll filled =0;
            for(ll j=0;j<temp.size() && filled<k ;j++)
            {
                if(sel.count(temp[j].ss)) continue;
                dp[i].pb(temp[j]);
                filled++;
                sel.insert(temp[j].ss); 
            }
        }
        for(ll i=0;i<k;i++)
        {
            cout<<dp[n][i].ff<<" ";
        }
        cout<<endl;
    }
    return 0;
}