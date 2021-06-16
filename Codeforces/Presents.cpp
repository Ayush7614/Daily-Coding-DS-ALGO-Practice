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
    ll arr[n+1];
    loop(i,1,n+1)
    {
        ll x;
        cin>>x;
        arr[x]=i;
    }
    loop(i,1,n+1)
        cout<<arr[i]<<" ";
    cout<<endl;    
    
    return 0;
}