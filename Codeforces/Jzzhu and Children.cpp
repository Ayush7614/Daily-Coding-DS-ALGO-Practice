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
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    ll index;
    ll maxVal=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ll q=arr[i]/m;
        if(q*m<arr[i])
        {
            arr[i]=q+1;
        }
        else
            arr[i]=q;
        if(arr[i]>=maxVal)
        {
            maxVal=arr[i];
            index=i;
        }
    }
    cout<<index+1;
  
    
    
    
    
    
    return 0;
}