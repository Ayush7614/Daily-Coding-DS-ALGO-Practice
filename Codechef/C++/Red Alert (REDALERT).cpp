#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,d,h,l=0,f=0;
    cin>>n>>d>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        l+=a[i];
        else
        {
            if((l-d) >0)
            l=l-d;
            else
            l=0;
        }
        if(l>h)
        {
            f++;
            break;
        }
    }
    if(f>0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
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