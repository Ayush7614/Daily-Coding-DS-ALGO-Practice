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

/*Test Cases

	Sample Input 1
		5 3
		10 30 40 50 20
	Sample Output 1
		30
	If we follow the path  1 ->2->5 the total cost incurred would be  |10 -30|+|30-20| = 30

	Sample Input 2
		3 1
		10 20 10
	Sample Output 2
		20

	Sample Input 3
		2 100
		10 10
	Sample Output 3
		0
*/
