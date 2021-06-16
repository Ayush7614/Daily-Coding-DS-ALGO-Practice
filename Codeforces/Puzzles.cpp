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
    ll n,m;
    cin>>n>>m;
    ll arr[m];
    loop(i,0,m)
        cin>>arr[i];
    sort(arr,arr+m);
    ll minDiff=INT_MAX;
    
    loop(i,0,m-n+1)
    {
        if(minDiff > abs(arr[i]-arr[i+n-1]))
            minDiff=abs(arr[i]-arr[i+n-1]);
    }
    cout<<minDiff<<endl;
    
    
    
    
    return 0;
}