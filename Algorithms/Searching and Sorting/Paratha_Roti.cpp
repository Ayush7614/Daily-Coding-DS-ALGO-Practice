#include <iostream>
#define int long long int
using namespace std;
int solve(int *a, int n, int par, int mid)
{
    int time = 0, paratha = 0;
    for (int i = 0; i < n; i++)
    {
        time = a[i];

        int j = 2;
        while (time <= mid)
        {
            paratha++;
            time = time + (a[i] * j);
            j++;
        }
        if (paratha >= par)
            return 1;
    }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int par;
        cin >> par;
        int n;
        cin >> n;
        int a[9];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int lb = 0;
        int ub = 1e8;
        int ans = 0;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (solve(a, n, par, mid))
            {

                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
