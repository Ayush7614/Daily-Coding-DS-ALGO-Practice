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
    cin>>n;
    ll a[n];
    loop(i,0,n)
        cin>>a[i];
    cin>>m;
    ll b[m];
    loop(i,0,m)
        cin>>b[i];
    
    ll maxRatio=0 , count=0 ;
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            if(b[j]/a[i] > maxRatio && b[j]%a[i]==0)
            {
                maxRatio= b[j]/a[i];
                count =1;
            }
            else if(b[j]/a[i]==maxRatio && b[j]%a[i]==0)
                count ++;
            
            
        }
    }
    cout<<count<<endl;
    
    
    
    return 0;
}