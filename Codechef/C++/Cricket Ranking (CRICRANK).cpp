#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a[3],b[3],cnt=0;
    for(int i=0;i<3;i++)
    cin>>a[i];
    for(int i=0;i<3;i++)
    cin>>b[i];
    for(int i=0;i<3;i++)
    {
        if(a[i]>b[i])
        cnt++;
    }
    if(cnt>1)
    cout<<"A\n";
    else
    cout<<"B\n";
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