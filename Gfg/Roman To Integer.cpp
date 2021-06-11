#include <bits/stdc++.h>
using namespace std;
int romanToDecimal(string &);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}
int romanToDecimal(string &str)
{
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    int n = str.size();
    int res = m[str[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        if (m[str[i + 1]] > m[str[i]])
        {
            res -= m[str[i]];
        }
        else
        {
            res += m[str[i]];
        }
    }
    return res;
}