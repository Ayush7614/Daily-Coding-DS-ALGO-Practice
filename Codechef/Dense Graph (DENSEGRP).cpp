#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> p1;
vector<ll> p2;
bool in_range(ll a,ll b){
    for(ll i=0;i<p1.size();i++){
        if(p1[i]<=b && p2[i]>=a){
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll a[m];
        ll b[m];
        ll c[m];
        ll d[m];
        for(ll i=0;i<m;i++){
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        }
        if(x==y){
            cout<<"0"<<endl;
            continue;
        }
    ll di[m];
    ll ans=-1;
    ll z=0;
    vector<ll> q1;
    vector<ll> q2;
    for(ll i=0;i<m;i++){
        di[i]=0;
    }
    q1.push_back(x);
    q2.push_back(x);
    while((ans==-1) && (q1.size()!=0)){
        p1.clear();
        p2.clear();
        p1=q1;
        p2=q2;
        vector<ll>w1;
        vector<ll>w2;
        for(ll i=0;i<(m);i++){
            if((di[i]==0) && in_range(a[i],b[i])){
                w1.push_back(c[i]);
                w2.push_back(d[i]);
                if(c[i]<=y && d[i]>=y){
                    ans=z+1;
                }
                di[i]=1;
            }
        }
        q1=w1;
        q2=w2;
        z++;
    }
    cout<<ans<<endl;
    }
    return 0;
}

/*
Example Input
3
5 2 1 2
1 2 4 5
5 5 2 3
6 1 3 4
1 6 3 3
2 1 2 2
1 1 1 1

Example Output
2
-1
0

*/