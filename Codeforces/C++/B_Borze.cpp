#include <bits/stdc++.h>
using namespace std;

// Question link : https://codeforces.com/problemset/problem/32/B

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
  string code;
  cin >> code;
  string decode = "";
  for (int i = 0; i < code.size(); ++i) {
    if (code[i] == '.')
      decode += "0";
    else if (code[i + 1] == '.') {
      decode += "1";
      ++i;
    } else {
        decode += "2";
        ++i;
    }
  }
  cout << decode << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solution();
}
