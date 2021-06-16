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
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll arr[4];
        loop(i,0,4)
            cin>>arr[i];
        ll a=max(arr[0],arr[1]);
        ll b=max(arr[2],arr[3]);
        sort(arr,arr+4);
        if((a==arr[3] || a==arr[2]) && (b==arr[2] || b==arr[3]))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        
    }
    
    
    return 0;
}