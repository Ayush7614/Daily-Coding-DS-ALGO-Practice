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
