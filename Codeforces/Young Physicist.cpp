#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
     ll sum=0;
    for(int i=0;i<3*n;i++)
        {
            int x;
            cin>>x;
            sum+=x;
        }
    if(sum==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
        
        
        
    
    
    
    
    return 0;
}