#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int g,c;
    cin>>g>>c;
    cout<<(c*c)/(2*g)<<"\n";
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

// Sample Input
// 3
// 7 1400
// 5 1000
// 10 1000

// Sample Output
// 140000
// 100000
// 50000