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
    ll n,k;
    cin>>n>>k;
    vector<int> v;
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    sort(arr,arr+n);
    ll ans;
    if(k==0)
        ans=arr[0]-1;
    else
        ans = arr[k-1];
    ll count =0;    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=ans)
            count++;
    }
    if(ans<1 || count!=k)
        cout<<-1<<endl;
    else
        cout<<ans;
    
    
    return 0;
}