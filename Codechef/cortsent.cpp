//qurestion https://www.codechef.com/START4C/problems/CORTSENT
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll p = 1000000000 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        bool valid = true;
        string s1, s2;

        cin >> k;
        while (k--)
        {
          cin >> s1;
            if (!valid)
                continue;
            
            bool a = true, b = true;
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] >= 97 && s1[i] <= 109)
                    a = false;
                else if (s1[i] >= 78 && s1[i] <= 90)
                    b = false;
                else
                    valid = false;
            }
            if (!a && !b)
                valid = false;
        }
        if (valid)
            cout << "\nYes";
        else
            cout << "\nNo";
    }
}