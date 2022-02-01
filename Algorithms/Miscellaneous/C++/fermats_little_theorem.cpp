
#include <bits/stdc++.h>
#define ll long long int
// Compute (A^B)%mod, where A and B are can have <10^6 digits.
using namespace std;
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll ans = power(a, b / 2, mod);
    ans %= mod;
    ans = (ans * ans) % mod;
    if ((b & 1) == 1)
        return (ans * a) % mod;
    return ans % mod;
}
ll stoi(string a, ll mod)
{
    ll ans = 0;
    for (size_t i = 0; i < a.length(); i++)
        ans = ((ans * 10) % mod + a[i] - '0') % mod;
    return ans;
}
int main()
{
    ll n, m, mod = 1000000007;
    ll t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        n = stoi(a, mod);
        m = stoi(b, mod - 1); // using fermats little theorem
        cout << power(n, m, mod) << endl;
    }
    return 0;
}

/*
Sample Input :
5
3 2
4 5
7 4
34534985349875439875439875349875 93475349759384754395743975349573495
34543987529435983745230948023948 3498573497543987543985743989120393097595572309482304
Sample Output :
9
1024
2401
735851262
985546465
*/
