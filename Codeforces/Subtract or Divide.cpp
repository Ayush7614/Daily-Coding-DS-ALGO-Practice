#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


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
        if(n>3)
        {
            if(n%2==0)
                cout<<2<<endl;
            else
                cout<<3<<endl;
        }
        else
        {
            cout<<n-1<<endl;
        }
        
        
    }
    
    
    
    return 0;
}