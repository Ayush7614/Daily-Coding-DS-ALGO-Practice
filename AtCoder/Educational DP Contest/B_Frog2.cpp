//https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;


int main()
{
	int N, k;
	cin >> N >> k;

	int dp[N];
	int ar[N];

	for (int i = 0; i < N; i++) cin >> ar[i];
	for (int i = 0; i < N; i++) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= max(0, i - k); j--) {
			dp[i] = min(dp[i], dp[j] + abs(ar[i] - ar[j]));
		}

	}
	
    cout << dp[N - 1];
    return 0;
}