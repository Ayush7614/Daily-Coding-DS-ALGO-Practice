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
    if((min(n,m))%2==0)
        cout<<"Malvika"<<endl;
    else
        cout<<"Akshat"<<endl;
    
    
    
    return 0;
}