#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define m 1000000007
int power(int x, unsigned int y, int p)
{
    int res = 1; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int32_t main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<power(2, n-1, m)<<endl;
    }
    return 0;
}
