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
    ll n;
    cin>>n;
    ll totalPass=0;
    ll prevPass=0;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        prevPass = prevPass  - a + b;
        if(prevPass> totalPass)
            totalPass=prevPass;
    }
    
    cout<<totalPass<<endl;
    
    return 0;
}