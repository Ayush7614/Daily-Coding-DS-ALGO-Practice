//question this is https://www.codechef.com/JUNE21C/problems/SHROUTE
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll p = 1e9;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n], b[m];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < m; i++)
            cin >> b[i];

        ll ans[n];
        ans[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != 0)
            {
                ans[i] = 0;
            }
            else
                ans[i] = p;
        }
        ll r = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                r = i;
            if (r != -1)
            {
                if (a[i] == 0)
                    ans[i] = min(ans[i], i - r);
            }
        }
        ll l = -1;
        for (int i = n-1; i >= 0; i--)
        {
            if (a[i] == 2)
                l=i;
            if (l != -1)
            {
                if (a[i] == 0)
                    ans[i] = min(ans[i],  l-i);
            }
        }
        ll j;
        for (ll i = 0; i < m; i++)
        {
            j = b[i] - 1;
            if (ans[j] != p)
            {
                cout << " " << ans[j];
            }
            else
                cout << " -1 ";
        }
        cout << "\n";
    }
}
