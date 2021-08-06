/*
    PROBLEM:
        AquaMoon and Cirno are playing an interesting game with arrays. Cirno has prepared two arrays a and b, both consist of n non-negative integers. AquaMoon can perform the following operation an arbitrary number of times (possibly zero):

        She chooses two indices i and j (1≤i,j≤n), then decreases the i-th element of array a by 1, and increases the j-th element of array a by 1. The resulting values at i-th and j-th index of array a are ai−1 and aj+1, respectively. Each element of array a must be non-negative after each operation. If i=j this operation doesn't change the array a.
        AquaMoon wants to make some operations to make arrays a and b equal. Two arrays a and b are considered equal if and only if ai=bi for all 1≤i≤n.

        Help AquaMoon to find a sequence of operations that will solve her problem or find, that it is impossible to make arrays a and b equal.

        Please note, that you don't have to minimize the number of operations.
        
    TEST CASE
        INPUT:
            4
            4
            1 2 3 4
            3 1 2 4
            2
            1 3
            2 1
            1
            0
            0
            5
            4 3 2 1 0
            0 1 2 3 4
        OUTPUT:
            2
            2 1
            3 1
            -1
            0
            6
            1 4
            1 4
            1 5
            1 5
            2 5
            2 5

*/

#include <bits/stdc++.h>
#define ll long int
#define vi vector
using namespace std;

int main()
{
    ll test;
    cin >> test;
    for (ll p = 0; p < test; p++)
    {
        struct node
        {
            int first;
            int second;
        };
        vi<node> m;
        int n, pos = 0, neg = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                pos += (a[i] - b[i]);
            }
            else if (a[i] < b[i])
            {
                neg += (b[i] - a[i]);
            }
        }
        if (pos != neg)
        {
            cout << "-1" << endl;
        }
        else if (pos == 0 && neg == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            while (1)
            {
                int aindex = 0, bindex = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] > b[i])
                    {
                        aindex = i;
                        break;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i] < b[i])
                    {
                        bindex = i;
                        break;
                    }
                }
                while (a[aindex] != b[aindex] && a[bindex] != b[bindex])
                {
                    node b;
                    a[aindex] -= 1;
                    a[bindex] += 1;
                    b.first = aindex + 1;
                    b.second = bindex + 1;
                    m.push_back(b);
                }
                if (aindex == 0 && bindex == 0)
                {
                    break;
                }
            }
            cout << m.size() << endl;
            for (auto i : m)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }

    return 0;
}