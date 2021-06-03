#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, x, y;
        cin >> p >> x >> y;
        int ans = 0;
        ans = x + (100 - p) * y;
        ans = ans * 10;
        cout << ans << endl;
    }
    return 0;
}