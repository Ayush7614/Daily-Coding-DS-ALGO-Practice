#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<=(b);i++)
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
        ll n,m,k;
        cin>>n>>m>>k;
        ll ans=0;
        ll a=1,b=1;
        while(1)
        {
           if(a==n && b==m)
            break;
            else if(a<n){
                a=a+1;
                ans=ans+b;
            }
            else if(a==n && b<m)
            {
                b=b+1;
                ans=ans+a;
            }
                
            
            
        }
        if(ans==k && a==n && b==m)
            cout<<"YES"<<endl;
        else
              cout<<"NO"<<endl;
            
        
        
    }
    
    
    
    return 0;
}