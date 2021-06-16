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
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    loop(i,0,n)
        cin>>arr[i];
    ll temp = arr[k-1];
    bool flag=false;
    loop(i,k-1,n)
    {
        if(arr[i]!=temp)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
    {
        ll index=-1;
        for(int i=0;i<k-1;i++)
        {
            if(arr[i]!=temp)
                index=i;
        }
        if(index+1> k)
            cout<<-1<<endl;
        else
            cout<<index+1<<endl;
    }
 return 0;
}