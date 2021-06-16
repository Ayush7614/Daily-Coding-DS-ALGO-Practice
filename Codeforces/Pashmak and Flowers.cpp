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
    sort(arr,arr+n);
    
    ll first = arr[0];
    ll second = arr[n-1];
    
    ll count1 = 0, count2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==first)
            count1++;
        else if(arr[i]==second)
            count2++;
    }
    cout<<abs(first-second)<<" ";
    if(first==second)
        cout<<(n*(n-1))/2<<endl;
    else
        cout<<(count1*count2)<<endl;
       
    
    
    
    
    return 0;
}