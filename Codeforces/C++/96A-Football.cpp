#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int c = 1, d = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == s[i + 1])
        {
            c++;
        }
        else
        {
            c = 1;
        }
        if (c == 7)
        {
            d = 1;
        }
    }
    if (d == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}