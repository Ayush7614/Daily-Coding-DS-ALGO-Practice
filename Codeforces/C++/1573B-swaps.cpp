#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#define INF 1 << 31 - 1
using namespace std;

void solve() {
   int n, e;
   cin >> n;
   vector<int> v1 = {};
   vector<int> v2 = {};
   vector<int> indexes (2 * n + 1, 0);
   for (int i = 0; i < n; i++) {
      cin >> e;
      v1.push_back(e);
      indexes[e] = i;
   }
   for (int i = 0; i < n; i++) {
      cin >> e;
      v2.push_back(e);
      indexes[e] = i;
   }
   if (v1[0] < v2[0]) {
      cout << 0 << endl;
      return;
   }
   int best_index = INF;
   int res = INF >> 3;
   for (int i = 2 * n; i > 0; i--) {
      if (i % 2 == 1) res = min(res, indexes[i] + best_index);
      else best_index = min(best_index, indexes[i]);
   }
   cout << res << endl;
}


int main () {
   int T;
   cin >> T;
   for (int t = 0; t < T; t++) {
      solve();
   }
}