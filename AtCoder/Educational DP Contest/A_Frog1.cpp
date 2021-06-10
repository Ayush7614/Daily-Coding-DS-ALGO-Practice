//https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
	int N;
	cin >> N;
	int ar[N];
	for (int i = 0; i < N; i++) cin >> ar[i];

	for (int i = 0; i < N; i++) {
		dp[i] = -1;
	}

	dp[0] = 0;
	dp[1]  = abs(ar[0] - ar[1]);

	for (int i = 2; i < N; i++) {
		if (dp[i - 1] + abs(ar[i] - ar[i - 1]) <  dp[i - 2] + abs(ar[i] - ar[i - 2])) {
			dp[i] = dp[i - 1] + abs(ar[i] - ar[i - 1]);
		} else {
			dp[i] = dp[i - 2] + abs(ar[i] - ar[i - 2]);
		}
	}

	cout << dp[N - 1];
	return 0;
}