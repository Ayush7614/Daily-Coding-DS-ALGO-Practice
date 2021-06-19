/*Question- You are given a positive integer n, it is guaranteed that n is even (i.e. divisible by 2).

You want to construct the array a of length n such that:

The first n2 elements of a are even (divisible by 2);
the second n2 elements of a are odd (not divisible by 2);
all elements of a are distinct and positive;
the sum of the first half equals to the sum of the second half (∑i=1n2ai=∑i=n2+1nai).
If there are multiple answers, you can print any. It is not guaranteed that the answer exists.

You have to answer t independent test cases.


INPUT
5
2
4
6
8
10

OUTPUT
NO
YES
2 4 1 5
NO
YES
2 4 6 8 1 3 5 11
NO

*/



#include <bits/stdc++.h>
#define ll long int
using namespace std;


int main()
{
    ll testcase;
    cin >> testcase;
    for (ll j = 0; j < testcase; j++)
    {
        ll num;
        cin >> num;
        if (num % 4 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            ll arr[num], k = 0;
            for (ll i = 0; i < num / 2; i++)
            {
                arr[i] = (i * 2) + 2;
            }
            for (ll i = num / 2; i < num; i++)
            {
                if (i != num - 1)
                {
                    arr[i] = (2 * k) + 1;
                    k++;
                }
                else if (i == num - 1)
                {
                    arr[i] = (3 * k) + 2;
                }
            }
            cout << "YES" << endl;
            for (ll i = 0; i < num; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
