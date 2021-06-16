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
        vector<ll> v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        
        sort(v.begin(),v.end());
        ll minEle=1e12;
        ll cnt=1;
        for(int i=1;i<n;++i)
        {
            if(v[i]<=0)
            {
                cnt++;
                minEle=min(minEle,v[i]-v[i - 1]);
            }
            if(v[i]>0)
            {
                if(v[i]-v[i-1]>=v[i]&&minEle>=v[i])
                    cnt++;
                break;
            }
        }
        cout<<cnt<<endl;
        
        
    }
    
    
    
    return 0;
}