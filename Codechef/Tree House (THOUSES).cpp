#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
using pii = pair<int, int>;
template <typename T>
using Prior = std::priority_queue<T, vector<T>, greater<T>>;

#define X first
#define Y second
#define eb emplace_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define fastIO() ios_base::sync_with_stdio, cin.tie(0)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int getRand(int L, int R)
{
    if (L > R)
        swap(L, R);
    return (int)(rng() % (uint64_t)(R - L + 1) + L);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i)
            os << " ";
    }
    return os;
}

const int maxn = 3E5 + 5;
const int mod = 1E9 + 7;

vector<int> adj[maxn], subval, val;
vector<pii> ch;

void dfs(int now, int lst = -1)
{
    for (auto x : adj[now])
    {
        if (x == lst)
            continue;
        dfs(x, now);
    }
    ch.clear();
    for (auto x : adj[now])
    {
        if (x != lst)
            ch.eb(subval[x], x);
    }
    sort(RALL(ch));

    int tok = 1;
    for (auto [_val, id] : ch)
        val[id] = tok++;
    for (auto x : adj[now])
    {
        if (x != lst)
            subval[now] += val[x] * subval[x];
    }
}

void solve()
{
    int N, X;
    cin >> N >> X;
    subval.assign(N, 1), val.assign(N, 0);
    for (int i = 0; i < N; ++i)
        vector<int>().swap(adj[i]);

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].eb(v), adj[v].eb(u);
    }

    dfs(0);

    cout << subval[0] % mod * X % mod << endl;
}

int32_t main()
{
    fastIO();

    int t;
    cin >> t;
    for (int _ = 1; _ <= t; ++_)
    {
        solve();
    }
    return 0;
}