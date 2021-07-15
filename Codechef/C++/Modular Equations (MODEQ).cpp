#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n, m;cin>>n>>m;
        int count_of_pair = 0;
        vector<int> modular_equation(n+1, 1);
        for(int a = 2;a<=n;a++)
        {
            int x = m%a;
            count_of_pair += modular_equation[x];
            for(int b = x;b<=n;b+=a)
            {
                modular_equation[b]++;
            }
        }
        cout<<count_of_pair<<endl;
    }
    return 0;
}