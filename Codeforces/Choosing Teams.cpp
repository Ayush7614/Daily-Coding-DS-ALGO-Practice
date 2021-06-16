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
    
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll count=0;
    loop(i,0,n)
    {
        cin>>arr[i];
        if(5-k>=arr[i])
            count++;
    }
    cout<<count/3<<endl;
    
    
    return 0;
}