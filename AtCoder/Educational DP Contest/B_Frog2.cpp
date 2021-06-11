//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, k;
	cin >> N >> k;
	int dp[N];
	int ar[N];
	for (int i = 0; i < N; i++) cin >> ar[i];
	for (int i = 0; i < N; i++) {
		dp[i] = INT_MAX; // initialized cost to reach stone i
	}
	dp[0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= max(0, i - k); j--) {
			dp[i] = min(dp[i], dp[j] + abs(ar[i] - ar[j]));//dp[i] contains minimum cost to reach stone i
		}

	}
	cout << dp[N - 1];
}