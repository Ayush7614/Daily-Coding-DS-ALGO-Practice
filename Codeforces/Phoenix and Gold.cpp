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
        ll n,x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        ll sum=0;
        vector<int> ans;
       bool flag=false;
            for(int i=0;i<n;i++)
        {
           sum= sum+v[i];
           if(sum==x)
           {
               if(i==n-1)
               {
                   flag=true;
                   break;
               }
               sum = sum-v[i];
               ll temp=v[i];
               v.erase(v.begin()+i);
               v.push_back(temp);
               i=i-1;
           }
           else if(sum!=x)
           {
               ans.push_back(v[i]);
           }
                
        }
        
        if(ans.size()==n && flag==false)
        {
            cout<<"YES"<<endl;
            loop(i,0,ans.size())
            cout<<ans[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
           
        v.clear();
        ans.clear();
    }
    
    
    
    return 0;
}