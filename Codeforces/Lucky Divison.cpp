#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>

bool isLucky(ll n)
{
    string s=to_string(n);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='4' && s[i]!='7')
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll num=4;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(isLucky(i) && n%i==0)
        {
            flag=true;
            break;
        }
        
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    
    return 0;
}