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
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll x= n/2;
    if(x*2<n)
        x+=1;
    if(k<=x)
    {
        cout<<(2*k)-1<<endl;
    
    }
    else
    {
        k=k-x;
        cout<<(2*k)<<endl;
    
    }
    
    
    
    
    return 0;
}