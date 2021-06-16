#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
    ll n,m;
    cin>>n>>m;
    ll count=2;
    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            if(i%2!=0 || (i%4==0 && j==1) || (i==count && j==m))
            {
                cout<<"#";
                if(i==count)
                    count+=4;
            }    
            
            else
                cout<<".";
        }
        cout<<endl;
    }
    
    
    
    
    return 0;
}