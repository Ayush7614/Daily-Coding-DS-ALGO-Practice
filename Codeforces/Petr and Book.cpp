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
    ll arr[8];
    loop(i,0,7)
        cin>>arr[i];
    int i; 
    bool flag=false;
    while(1)
    {
    for(i=0;i<7;i++)
    {
        if(arr[i]>=n)
        {
            flag=true;
            break;
        }
       
        else if(arr[i]<n)
        {
            n = n-arr[i];
        }
    }
    if(flag==false)
    i=0;
    else break;
}
    cout<<i+1<<endl;
    
    
    return 0;
}