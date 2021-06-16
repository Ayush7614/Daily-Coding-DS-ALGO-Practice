#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int maxN=1e5+100;
pair<ll,ll> v[maxN];
int main()
{
    fastio();
    
    ll n;
    cin>>n;
    
    loop(i,0,n)
        cin>>v[i].first>>v[i].second;
    sort(v,v+n);
    ll mx=INT_MIN;
    bool flag=false;
    loop(i,0,n)
    {
        mx=max(mx,(v[i].second));
        if(mx!=v[i].second)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"Happy Alex"<<endl;
    else
        cout<<"Poor Alex"<<endl;
    
    
    return 0;
}