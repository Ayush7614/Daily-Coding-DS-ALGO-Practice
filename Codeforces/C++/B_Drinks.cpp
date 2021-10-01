#include <bits/stdc++.h>
using namespace std;

// Question link : https://codeforces.com/problemset/problem/200/B

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define eps 1e-9
#define PI 3.14
#define MOD 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define in_arr(v, n)                                                           \
  for (int i = 0; i < n; i++)                                                  \
  cin >> v[i]
#define out_arr(v, n)                                                          \
  for (int i = 0; i < n; i++)                                                  \
  cout << v[i] << " "

void solution() {
  // code here
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    sum += temp;
  }
  cout << fixed << setprecision(12) << (double)sum / n << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--)
    solution();
}
