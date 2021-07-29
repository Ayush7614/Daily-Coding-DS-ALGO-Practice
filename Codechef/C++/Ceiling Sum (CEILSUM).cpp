#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int a,b;
    cin>>a>>b;
    if(a==b)
    cout<<"0";
    else
    {
        if((b-a)%2 == 0)
        cout<<(b-a+2)/2;
        else
        cout<<(b-a+1)/2;
    }
    cout<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

// Sample input/output 

// Sample Input 1 
// 3
// 2 2
// 1 11
// 13 6

// Sample Output 1 
// 0
// 6
// -3