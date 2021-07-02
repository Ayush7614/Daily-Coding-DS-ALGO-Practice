#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int k,d0,d1,sum=0,s,cvalue,cycles,left,lvalue=0,temp;
    cin>>k>>d0>>d1;
    s=d0+d1;
    if(k==2)
    sum=s;
    else
    {
        cvalue = ((2*s)%10) + ((4*s)%10) + ((8*s)%10) + ((6*s)%10);
        cycles=(k-3)/4;
        left = (k-3)%4;
        temp=2;
        while(left--)
        {
            lvalue = lvalue + (temp*s)%10;
            temp = (temp*2)%10;
        }
        sum = s + s%10 + cycles*cvalue + lvalue;
    }
    if(sum%3==0)
    cout<<"YES";
    else 
    cout<<"NO";
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