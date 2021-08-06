#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>

ll isDivisible(ll n)
{
    if(n%5==0)
    {
        if(n%15==0)
        {
            if(n%75==0)
                return 3;
            return 2;    
        }
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<isDivisible(n)<<endl;
        
        
    }
    
    
    
    return 0;
}