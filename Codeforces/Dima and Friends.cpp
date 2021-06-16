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
    ll n,sum=0;
    cin>>n;
    ll arr[n];
    loop(i,0,n){
        cin>>arr[i];
        sum +=arr[i];
    }    
    ll count =0;
    ll fingers=5;
    while(fingers>0)
    {
        if((sum+fingers)%(n+1)!=1)
            count++;
        fingers--;
    }
    
    
    cout<<count<<endl;
    
    
    return 0;
}