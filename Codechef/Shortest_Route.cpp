#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int max = 1e9;
        map<int, int> mp;
        for (i = 0; i < n; i++)
        {
            if (i == 0)
                mp[i] = 0;
            else if (a[i] != 0)
                mp[i] = 0;
            else
                mp[i] = max;
        }
        int right = -1;
        for (i = 0; i < n; i++)
        {
            if (a[i] == 1)
                right = i;
            if (right != -1)
            {
                if (a[i] == 0)
                    mp[i] = min(mp[i], i - right);
            }
        }
        int left = -1;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] == 2)
                left = i;
            if (left != -1)
            {
                if (a[i] == 0)
                    mp[i] = min(mp[i], left - i);
            }
        }
        for (i = 0; i < m; i++)
        {
            int j = b[i] - 1;
            if (mp[j] != max)
                cout << mp[j] << " ";
            else
                cout << -1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
/* 
Sample Test Cases
------------------

Sample Input
3
5 1
1 0 0 0 0
5
5 1
1 0 0 0 2
4
5 2
2 0 0 0 1
3 1

Sample Output
4
1
-1 0

Explanation
------------

Test Case 1: The only person takes the train from station 1 and hence takes |5−1|=4 minutes to reach his destination.

Test Case 2: The only person takes the train from station 5 and hence takes |5−4|=1 minute to reach his destination.

Test Case 3: Since no train passes station 3,
it's impossible for the first person to reach his destination and since the second person is already at station 1,
it takes him 0 minutes to reach his destination.
*/