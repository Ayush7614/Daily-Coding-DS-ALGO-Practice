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
    ll c[n+1]={0};
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        c[x]++;
        
    }
    if(c[1]!=n/3 || c[2]+c[3]!=n/3 || c[4]+c[6]!=n/3 || c[4]> c[2])
        cout<<-1<<endl;
    else
    {
        for(int i=1;i<=n/3;i++)
        {
        cout<<1<<" ";
        c[1]--;
        if(c[2]>0)
        {
            cout<<2<<" ";
            c[2]--;
            if(c[4]>0)
            {
                cout<<4<<endl;
                c[4]--;
            }
            else
            {
                cout<<6<<endl;
                c[6]--;
            }
        }
        else
        {
            cout<<3<<" ";
            c[3]--;
            cout<<6<<endl;
            c[6]--;
        }
        }
    }
        
    
    
    
    return 0;
}