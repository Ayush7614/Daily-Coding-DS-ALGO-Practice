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
    ll n,m;
    cin>>n>>m;
    multiset<int> minValue;
    multiset<int,greater<int>> maxValue;
    loop(i,0,m)
    {
        ll k;
        cin>>k;
        minValue.insert(k);
        maxValue.insert(k);
    }
    
    int minProfit = 0, maxProfit = 0;
    loop(i,0,n)
    {
        int x = *minValue.begin();
        minProfit += x;
        minValue.erase(minValue.lower_bound(x));
        x--;
        if(x>0)
            minValue.insert(x);
        
    }
    
    loop(i,0,n)
    {
        int x= *maxValue.begin();
        maxProfit +=x;
        maxValue.erase(maxValue.lower_bound(x));
        x--;
        if(x>0)
            maxValue.insert(x);
        
    }
    cout<<maxProfit<<" "<<minProfit<<endl;        
    
    
    
    return 0;
}