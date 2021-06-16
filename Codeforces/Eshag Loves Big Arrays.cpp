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
        ll arr[n];
        loop(i,0,n)
            cin>>arr[i];
        bool isSame=1;
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                isSame=0;
                break;
            }
        }
        if(isSame)
            cout<<0<<endl;
        else
        {
            ll val=0;
            for(int i=0;i<n-1;i++)
            {
                if(arr[i]!=arr[i+1])
                {
                    val=i+1;
                    break;
                }
            }
            cout<<(n-val)<<endl;
        }
        
        
    }
    
    
    
    return 0;
}