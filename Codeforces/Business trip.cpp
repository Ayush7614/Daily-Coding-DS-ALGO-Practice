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
    ll k;
    cin>>k;
    int arr[12];
    loop(i,0,12)
        cin>>arr[i];
    sort(arr,arr+12,greater<int>());
    
    int count=0;
    ll height=0;
    loop(i,0,12)
    {
        if(height<k)
        {
            height+=arr[i];
            count++;
        }
        else if(height>=k)
            break;
    }
    if(height<k)
        cout<<-1<<endl;
    else
        cout<<count<<endl;
    
    
    
    
    return 0;
}