#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int min_xor = INT_MAX, val = 0;

    for (int i = 1; i < n; i++)
    {
        val = a[i] ^ a[i - 1];
        min_xor = min(min_xor, val);
    }

    cout << min_xor << endl;
}