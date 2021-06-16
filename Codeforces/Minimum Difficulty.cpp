#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
    ll n;
    cin>>n;
    vector<ll> height,arr;
    loop(i,0,n)
    {
        ll x;
        cin>>x;
        height.push_back(x);
        
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    
    ll j=2,diff;
    while(j<n)
    {
        arr=height;
        arr.erase(arr.begin()+j-1);
        diff=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            diff=max(diff,arr[i+1]-arr[i]);
        }
        pq.push(diff);
        j++;
        
    }
    
    cout<<pq.top()<<endl;
    
    return 0;
}