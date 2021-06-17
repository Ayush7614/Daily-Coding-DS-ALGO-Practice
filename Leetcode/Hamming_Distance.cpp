#include <bits/stdc++.h>
using namespace std;
int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int setBits = 0;
    while (x > 0) {
     setBits += x & 1;
      x >>= 1;
   }
   return setBits;
}
int main()
{
  int n1 = 9, n2 = 14;
  cout << hammingDistance(9, 14) << endl;
    return 0;
}
