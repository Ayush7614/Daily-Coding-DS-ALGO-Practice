#include <bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 10000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n - k == 1)
            cout << -1;
        else if (n == k)
            for (int i = 1; i <= n; i++)
                cout << i << nline;
        else {
            for (int i = 1; i <= k; i++)
                cout << i << " ";
            cout << n << " ";
            for (int i = k + 1; i < n; i++)
                cout << i << " ";
        }
        cout << nline;
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
