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
    ll n,d;
    cin>>n>>d;
    ll arr[n],sum=0;
    loop(i,0,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll jokeTime=10*(n-1);
    if(jokeTime+sum>d)
        cout<<-1<<endl;
    else
    {
        int a=d-(jokeTime+sum);
        a=a/5;
        a=a+(2*(n-1));
        cout<<a<<endl;
    }
    
    
    
    return 0;
}