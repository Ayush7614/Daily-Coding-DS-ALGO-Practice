#include <bits/stdc++.h>
using namespace std;
int ans=0;

void rec(int i,int n,string osf)
{
    if(i==n-1)
    {
        ans++;
        cout<<osf<<endl;
        return;
    }
    if(i>=n)
        return;

    rec(i+1,n,osf+"1");
    rec(i+2,n,osf+"2");
    rec(i+3,n,osf+"3");
    rec(i+4,n,osf+"4");
    rec(i+5,n,osf+"5");
    rec(i+6,n,osf+"6");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       ans=0;
       rec(0,n,"");
       cout<<ans<<endl;
    }
    return 0;
}
