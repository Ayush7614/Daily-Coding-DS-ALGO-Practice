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
    ll height[n];
    loop(i,0,n)
        cin>>height[i];
    ll minDiff=abs(height[0]-height[n-1]),firstIndex=0,lastIndex=n-1;
    loop(i,0,n-1)
    {
        if(abs(height[i]-height[i+1])<minDiff)
        {
            minDiff=abs(height[i]-height[i+1]);
            firstIndex=i;
            lastIndex=i+1;
        }
    }
    
    cout<<firstIndex+1<<" "<<lastIndex+1<<endl;
    
    
    
    return 0;
}