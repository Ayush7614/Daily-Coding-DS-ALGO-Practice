#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
ll find_two(ll el)
{
    ll num = 1;
    while (num < el)
    {
        num = num * 2;
    }
    if (num != el)
        num = num / 2;
    return num;
}
void print_arr(ll arr[], int n)
{
    rep(i, n) cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll x;
        cin >> n >> x;
        ll arr[n];
        bool alleven = true, sorted = true;
        rep(i, n)
        {
            cin >> arr[i];
            if (arr[i] % 2 != 0)
                alleven = false;
            // if(i>0 && arr[i]<arr[i-1]) sorted=false;
        }
        int j = 0;
        ll i = 0;
        while (i < x)
        {
            if (j == n - 1)
                break;
            if (arr[j] == 0)
            {
                j++;
                continue;
            }
            ll max_2 = find_two(arr[j]);
            int k = j + 1;
            for (; k < n - 1; k++)
            {
                ll el = arr[k] ^ max_2;
                if (el < arr[k])
                    break;
            }
            arr[j] = arr[j] ^ max_2;
            arr[k] = arr[k] ^ max_2;
            i++;
            // print_arr(arr,n);
        }
        ll rem = x - i;
        if (n == 2 && rem > 0 && rem % 2 != 0)
        {
            arr[n - 1] ^= 1;
            arr[n - 2] ^= 1;
        }
        print_arr(arr, n);
    }
    return 0;
}

/*
 Sample Test Cases
 ------------------

Example Input

1
3 3
2 2 3

Example Output

0 0 3

Explanation
------------

Example case 1:

The original sequence is (2,2,3). Consider the following three operations:
Choose i=1, j=2 and p=1. 
Then, A1 changes from 2 to 2⊕21=0 and similarly,
A2 changes from 2 to 2⊕21=0. Now the sequence is (0,0,3).

Next, choose i=1, j=2 and p=1. Then, A1 changes to 0⊕21=2 and A2 changes to 0⊕21=2.
The sequence is (2,2,3).

Next, again choose i=1, j=2 and p=1.
Then, A1 changes to 2⊕21=0 and A2 changes to 2⊕21=0. 
The sequence is (0,0,3) again.

We can check that after exactly 3 operations, this is the lexicographically smallest sequence we can obtain.
*/