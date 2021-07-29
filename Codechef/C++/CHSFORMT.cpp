#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a,b,s;
    cin>>a>>b;
    s=a+b;
    if(s<3)
    cout<<"1";
    else if (s>=3 && s<=10)
    cout<<"2";
    else if(s>=11 && s<=60)
    cout<<"3";
    else
    cout<<"4";
    cout<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}