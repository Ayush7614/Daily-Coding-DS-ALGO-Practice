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
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    ll minScore=arr[0],maxScore=arr[0],count=0;
    loop(i,1,n)
    {
        if(arr[i]>maxScore)
        {
            maxScore=arr[i];
            count++;
        }
        if(arr[i]<minScore)
        {
            minScore=arr[i];
            count++;
        }
        else
        continue;
        
    }
    cout<<count<<endl;
    
    
    
    return 0;
}