#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll chk[n];
    for(ll i = 0; i<n; i++)
    {
        cin>>arr[i];
        chk[i] = 1;
    }
    for(ll i = 1; i<n; i++)
    {
        if(arr[i]>arr[i-1] && !(chk[i]>chk[i-1]))
        {
            chk[i]= chk[i-1] + 1;
        }
    }
    
    for(ll i = n-2; i>=0; i--)
    {
        if(arr[i]>arr[i+1] && !(chk[i]>chk[i+1]))
        {
            chk[i]= chk[i+1] + 1;
        }
    }
    ll sum = 0;
    for(ll i = 0; i<n; i++)
    {
        sum  = sum + chk[i];
    }
    
    cout<<sum<<endl;
    
    return 0;

}

