#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>

void rotate(ll arr[],ll n)
{
    ll temp = arr[n-1];
    for(int i=n-1;i>=1;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;  
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        k=k%n;
        loop(i,0,n)
            cin>>arr[i];
        while(k--)
            rotate(arr,n);
        loop(i,0,n) 
            cout<<arr[i]<<" ";
        cout<<endl;    
        
    }
    
    
    
    return 0;
}