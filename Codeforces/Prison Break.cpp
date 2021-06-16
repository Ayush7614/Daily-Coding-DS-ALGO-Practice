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
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
        cout<<(max(r-1,n-r)+max(c-1,m-c))<<endl;
        
        
    }
    
    
    
    return 0;
}