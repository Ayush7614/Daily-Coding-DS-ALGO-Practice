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
    ll p,q,x;
    set<ll> range;
    cin>>p;
    loop(i,0,p)
    {
        cin>>x;
        range.insert(x);
    }
    cin>>q;
    loop(i,0,q)
    {
        cin>>x;
        range.insert(x);
    }
    if(p==0 && q==0)
          cout<<"Oh, my keyboard!"<<endl;
    else if((*--range.end())==n && (*range.begin()==1) && range.size()==n)
        cout<<"I become the guy."<<endl;
     else
        cout<<"Oh, my keyboard!"<<endl;
    
    
    
    return 0;
}