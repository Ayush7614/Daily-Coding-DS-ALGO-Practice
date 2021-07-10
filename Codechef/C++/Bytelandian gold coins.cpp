#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> dp;

ll profit(ll n) {
	if (n == 0LL) {
		return n;
	}
	if (dp.find(n) != dp.end()) {
		return dp[n];
	}
	
	ll ans = max(n, profit(n / 2LL) + profit(n / 3LL) + profit(n / 4LL));
	return dp[n] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	dp[0LL] = 0LL;
	while (cin >> n) {
		cout << profit(n) << '\n';
	}
	
	return 0;
}
