#include <bits/stdc++.h>
using namespace std;

// Question link : https://codeforces.com/contest/1520/problem/D

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define MAX 9223372036854775807
#define fucking ios_base::sync_with_stdio(false)
#define fastIO cin.tie(0)

void solution()
{
    //code here
    int n;
    cin >> n;
    map<int, int> a;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x -= i;
        res += a[x];
        a[x]++;
    }
    cout << res << endl;
}

signed main()
{
    fucking;
    fastIO;
    int t = 1;
    cin >> t;
    while (t--)
        solution();
}
