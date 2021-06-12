#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rec(string s,ll i,string temp,ll n)
{
    if(i==n)
    {
        cout<<temp<<" ";
        return;
    }

    for(ll j=i;j<n;j++)
    {
        swap(s[i],s[j]);
        rec(s,i+1,temp+s[i],n);
        swap(s[i],s[j]);
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        ll i,j,n;
        n=s.size();
        rec(s,0,"",n);
        cout<<endl;
    }
    return 0;
}
