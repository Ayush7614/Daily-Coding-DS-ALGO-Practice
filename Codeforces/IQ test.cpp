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
    
    ll n;
    cin>>n;
    ll countOdd=0,countEven=0,indexOdd=-1,indexEven=-1;
    ll arr[n];
    loop(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]%2==0)
        {
            countEven++;
            indexEven=i;
        }
        else
        {
            countOdd++;
            indexOdd=i;
        }
    }
    if(countOdd==1)
        cout<<indexOdd+1<<endl;
    else
        cout<<indexEven+1<<endl;
    
    
    
    return 0;
}