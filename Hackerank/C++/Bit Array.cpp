//Problem Link: https://www.hackerrank.com/challenges/bitset-1/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int N, S, P, Q, mu, nu;

    const unsigned int m = 1 << 31;

    cin >> N >> S >> P >> Q;

    unsigned int *a = new unsigned int[N];

    a[0] = S % m;

    for (int i = 1; i < N; i++)
    {
        a[i] = (a[i - 1] * P + Q) % m;
    }

    for (int i = 0; i < N; i++)
    {

        if ((2 * i) + 1 > N - 1)
        {
            cout << N;
            delete[] a;
            return 0;
        }
        else if (a[i] == a[(2 * i) + 1])
        {
            nu = i + 1;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {

        if (a[i] == a[i + nu])
        {
            mu = i;
            break;
        }
    }

    for (int i = mu + 1; i < N; i++)
    {
        if (a[mu] == a[i])
        {
            cout << i;
            break;
        }
    }

    delete[] a;
    return 0;
}