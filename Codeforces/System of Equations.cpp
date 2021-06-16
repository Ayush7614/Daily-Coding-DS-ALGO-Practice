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
    ll n,m;
    cin>>n>>m;
    ll count = 0;
    
    loop(i,0,n+1)
    {
        loop(j,0,m+1)
        {
            if(((i*i)+j==n ) && (i+(j*j)==m))
                count++;
            
        }
        
    }
    cout<<count<<endl;
    
    
    return 0;
}s