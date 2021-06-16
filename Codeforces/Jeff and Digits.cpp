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
    ll countZero=0,countFive=0;
    loop(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]==0)
            countZero++;
        else
            countFive++;
    }
    if(countZero==0)
        cout<<-1<<endl;
    else if(countFive>=9)
    {
        for(int i=1;i<=countFive/9;i++)
            cout<<555555555;
        for(int i=1;i<=countZero;i++)
            cout<<0;
        cout<<endl;    
    }
    else if(countFive<9)
        cout<<0<<endl;
    else 
        cout<<-1<<endl;
    
    
    return 0;
}s