#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
#include<string>
#define ll long long
#define mod 1000000007
#define pb push_back


#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int main() {
  fast_io;

  init_code();
  int n;
  cin >> n;

  string s;

  cin >> s;



  map<string, int>mp;
  for (int i = 0; i < n - 1; i++) {
    mp[s.substr(i, 2)]++;

  }
  int max = 0;
  string max_char;
  for (auto &x : mp) {
    if (x.second >= max) {
      max_char = x.first;
      max = x.second;

    }
  }
 

  cout << max_char << endl;






  return 0;
}
