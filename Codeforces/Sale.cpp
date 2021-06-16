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
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    ll maxProfit = 0;
    sort(arr,arr+n);
    loop(i,0,m)
    {
        if(arr[i]<0)
        maxProfit +=arr[i];
            
        
    }
    cout<<abs(maxProfit)<<endl;
    
    
    
    return 0;
}