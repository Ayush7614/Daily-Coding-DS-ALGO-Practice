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
    ll t;
    cin>>t;
    while(t--)
    {
    ll r,b,d;
    cin>>r>>b>>d;
    if(r>b)
        swap(r,b);
    if(b>(r*(d+1))) 
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    }
    
    return 0;
}