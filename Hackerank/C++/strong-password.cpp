#include "bits/stdc++.h"
using namespace std;

const int N = 200005;

int get(char c) {
   if(c >= '0' && c <= '9') return 0;
   if(c >= 'a' && c <= 'z') return 1;
   if(c >= 'A' && c <= 'Z') return 2;
   return 3;
}

int main() {
   int n;
   string s;

   cin >> n;
   cin >> s;

   int ans = 0;

   for(int i = 0; i < n; i++) {
      ans |= (1 << get(s[i]));
   }

   cout << max(6 - n, 4 - __builtin_popcount(ans));
   return 0;
}