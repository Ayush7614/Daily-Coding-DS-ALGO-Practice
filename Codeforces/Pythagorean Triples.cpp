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
        int n;
        cin>>n;
        int ans = 0;
        for(int i=3;i*i<=2*n-1;i+=2)
            ++ans;
        cout <<ans<<'\n';
        
    }
    
    
    
    return 0;
}