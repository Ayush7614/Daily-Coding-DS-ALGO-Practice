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
    ll dist[n];
    loop(i,0,n)
        cin>>dist[i];
    ll minDist=0;
    bool flag=false;
    loop(i,1,n)
    {
        if(dist[i]==dist[minDist])
            flag=true;
        else if(dist[i]<dist[minDist])
        {
            minDist=i;
            flag=false;
        }    
            
    }
    if(flag==true)
        cout<<"Still Rozdil"<<endl;
    else
        cout<<minDist+1<<endl;
    
    
    
    
    return 0;
}