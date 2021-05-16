//Problem Link: https://www.codechef.com/MARCH21C/problems/IRSTXOR
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // your code goes here
    long long int t, c, x, f, ma, i, temp, p, a, b;
    cin >> t;
    while (t--)
    {
        cin >> c;
        f = 0;
        f = int(log2(c));
        p = pow(2, f);
        a = p - 1;
        b = a ^ c;
        cout << a * b << endl;
    }
    return 0;
}
