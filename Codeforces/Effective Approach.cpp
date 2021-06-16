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
    ll arr[n+1],b[n+1];
    loop(i,1,n+1)
    {
        cin>>arr[i];
        b[arr[i]]=i;
    }
    
    ll q,vasya =0,petya =0;
    cin>>q;
    while(q--)
    {
        ll query;
        cin>>query;
        vasya +=b[query];
        petya +=(n-b[query]+1);
        
    }
    cout<<vasya<<" "<<petya<<endl;
    
    
    return 0;
}