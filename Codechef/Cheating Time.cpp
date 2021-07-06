#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
                             
int main(void)
{
       ll t;
       cin>>t;
       while(t--)
       {
              ll n,m,k,f,i;
              cin>>n>>k>>f;
              vector<pair<ll,ll>> pq;
              for(i=0;i<n;i++)
              {
                        ll a,b;
                        cin>>a>>b;
                        pq.push_back({a,b});
              }
              sort(pq.begin(),pq.end());
              ll ans=0;
              ans+=pq[0].ff;
              ll x=pq[0].ff,y=pq[0].ss;
              for(i=1;i<n;i++)
              {
                    if(pq[i].ff>y){
                        
                            ans+=pq[i].ff-y;
                            y=max(y,pq[i].ss);
                    }
                        
                        else{
                            y=max(y,pq[i].ss);
                        }
                        
             }
             
             ans+=(f-y);
            if(ans>=k)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
                                                
                            
       }                             
            
   
}

//sample input
// 3
// 1 10 10
// 0 10
// 2 2 10
// 0 5
// 7 10
// 2 2 100
// 0 5
// 5 10

//sample output
NO
YES
YES



