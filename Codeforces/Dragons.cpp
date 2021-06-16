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
    ll n,s;
    cin>>s>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    bool flag=false;
    for(auto it:v)
    {
        if((it.first) < s)
        {
            s +=(it.second);
        }
        else
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    
    
    return 0;
}