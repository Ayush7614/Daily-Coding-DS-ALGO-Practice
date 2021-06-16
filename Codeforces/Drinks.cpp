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
    ll n;
    cin>> n;
    double arr[n];
    loop(i,0,n-1)
        cin>>arr[i];
    double upper  = 0;
    for(int i=0;i<n;i++)
    {
        upper += arr[i]/100.0;
        
    }
    double ans = upper / n;
    cout<<ans*100.0<<endl;
    
    
    
    return 0;
}