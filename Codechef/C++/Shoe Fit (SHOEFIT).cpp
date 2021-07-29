#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a,b,c,ans;
    cin>>a>>b>>c;
    ans=a+b+c;
    if(ans>0 && ans<3)
    cout<<"1";
    else
    cout<<"0";
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
// 0 0 0
// 0 1 1
// 1 0 1

// Sample Output 1 
// 0
// 1
// 1