#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n) ;
        for(int i=0;i<n;i++)
        cin>>v[i];
        vector<int>  a=v;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(v[i]!=a[1])
            {
                cout<<i+1<<endl;
            }
        }
        
        
        
    }
    
    
    
    return 0;
}