//Problem Link: https://www.codechef.com/CLWC2021/problems/CLWI21D

#include <iostream>
using namespace std;

int main()
{
    long long int t, n, s, c, tc;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s = 0;
        c = 1;
        tc = 0;
        while (tc != n)
        {
            if (n - tc < c)
            {
                s = s + (n - tc) * c;
                tc = n;
            }
            else
            {
                s = s + c * c;
                tc = tc + c;
            }
            c++;
        }
        cout << s << endl;
    }
    return 0;
}
