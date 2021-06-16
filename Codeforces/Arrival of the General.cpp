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
    ll minElem=INT_MAX,minIndex=-1,maxIndex=-1,maxElem=INT_MIN;
    loop(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]<=minElem)
        {
            minElem=arr[i];
            minIndex=i;
        }    
        if(arr[i]>=maxElem)
        {
            maxElem=arr[i];
            maxIndex=i;
        }    
    }
    
    if(arr[0]==maxElem && arr[n-1]==minElem)
        cout<<0<<endl;
    else
    {
        ll count=0;
        for(int i=minIndex;i<n-1;i++)
        {
            swap(arr[i],arr[i+1]);
            count++;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==maxElem)
            {
                maxIndex=i;
                break;
            }    
        }
        
        cout<<(count+maxIndex)<<endl;
    }
    
    
    return 0;
}