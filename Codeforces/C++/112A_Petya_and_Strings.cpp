
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string a, b;
int main()
{
    cin >> a >> b;
    //Taking two inouts here.
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 92)
        {
            a[i] += 32;
        }
        if (b[i] < 92)
        {
            b[i] += 32;
        }
    }
    if (a < b)
    {
        cout << -1;
    }
    else if (a > b)
    {
        cout << 1;
    }
    else if (a == b)
    {
        cout << 0;
    }
}