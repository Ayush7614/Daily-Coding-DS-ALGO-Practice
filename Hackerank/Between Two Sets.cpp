#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    for(ll i=0;i<n;i++)    cin>>a[i];
    for(ll i=0;i<m;i++)    cin>>b[i];
    ll c=0;
    for(ll i=1;i<=100;i++)
    {
        bool ha=true,haa=true;
        for(ll j=0;j<n;j++)
        {
            if(i%a[j]!=0)
            {
                ha=false;
                break;
            }
        }
        for(ll j=0;j<m;j++)
        {
            if(b[j]%i!=0)
            {
                haa=false;
                break;
            }
        }
        if(ha && haa)
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}
