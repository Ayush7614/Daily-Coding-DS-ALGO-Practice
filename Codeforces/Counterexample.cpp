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
    
    ll l,r;
    cin>>l>>r;
    if(r-l+1<3)
        cout<<-1<<endl;
    else if(l%2==0)
        cout<<l<<" "<<l+1<<" "<<l+2<<endl;    
    else if(r-l+1>3)
        cout<<l+1<<" "<<l+2<<" "<<l+3<<endl;
    
    else
        cout<<-1<<endl;
    
    return 0;
}