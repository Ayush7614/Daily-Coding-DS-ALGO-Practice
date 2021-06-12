#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rec(ll i,ll j,ll n,string s)
{
    if(i==n and j==n)
    {
        cout<<s<<endl;
        return;
    }

    if(i==n)
     rec(i,j+1,n,s+')');
    else
    {
       rec(i+1,j,n,s+'(');
       if(j<i)
       rec(i,j+1,n,s+')');
    }
}

int main()
{
    ll n;
    cin>>n;

    rec(0,0,n,"");
    return 0;
}
