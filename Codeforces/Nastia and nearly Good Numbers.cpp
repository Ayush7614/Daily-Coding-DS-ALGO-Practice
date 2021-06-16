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
        ll a,b;
        cin>>a>>b;
        if(b==1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<a*b+a*(b-1)<<" "<<(a+(a*b)+(a*(b-1)))<<endl;
        }
    }
    
    
    
    return 0;
}