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
    ll n;
    cin>>n;
    vector<pair<int,int>> v;
    int maxElement = INT_MIN,minElement=INT_MAX;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
        if(x<minElement)
            minElement=x;
        if(y>maxElement)
            maxElement=y;
    }
    bool flag = false;
    for(ll i=0;i<n;i++)
    {
        if(v[i].first==minElement && v[i].second==maxElement)
        {
            cout<<i+1<<endl;
            flag=true;
            break;
        }    
    }
    if(flag==false)
        cout<<-1<<endl;
    
    return 0;
}