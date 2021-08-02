#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a[3];
    for(int i=0;i<3;i++)
    cin>>a[i];
    sort(a,a+3);
    cout<<a[1]+a[2]<<"\n";  

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