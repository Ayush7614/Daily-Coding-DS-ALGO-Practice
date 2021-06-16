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
    
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    ll minELem=INT_MAX,maxElem=INT_MIN,c=INT_MAX;
    loop(i,0,n)
    {
        cin>>a[i];
        if(a[i]>=maxElem)
            maxElem=a[i];
        if(a[i]<=minELem)
            minELem=a[i];
    }
    
    loop(i,0,m)
    {
        cin>>b[i];
        if(b[i]<c)
            c=b[i];
    }        
    if(max(2*minELem,maxElem)<c)
        cout<<max(2*minELem,maxElem)<<endl;
    else
        cout<<-1<<endl;
    
    
    return 0;
}