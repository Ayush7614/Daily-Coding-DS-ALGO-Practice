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
    ll arr[n],totalSum=0;
    loop(i,0,n)
    {
        cin>>arr[i];
        totalSum+=arr[i];
    }
    sort(arr,arr+n,greater<int>());
    ll count=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        count++;
        totalSum-=arr[i];
        if(sum>totalSum)
            break;
    }
    
    cout<<count<<endl;
    
    
    return 0;
}