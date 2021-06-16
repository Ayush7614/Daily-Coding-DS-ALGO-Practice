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
        map<int,int> mp;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        ll ans=-1;
        for(auto it:mp)
        {
            if(it.second==1){
                ans=it.first;
                break;
            }    
        }
        if(ans==-1)
            cout<<-1<<endl;
        else
        {
            loop(i,0,n)
            {
                if(arr[i]==ans)
                {
                    cout<<i+1<<endl;
                    break;
                }
            }
            
        }
        
    }
    
    
    
    return 0;
}