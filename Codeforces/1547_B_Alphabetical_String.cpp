/*
Problem:
    A string s of length n (1≤n≤26) is called alphabetical if it can be obtained using the following algorithm:

    first, write an empty string to s (i.e. perform the assignment s := "");
    then perform the next step n times;
    at the i-th step take i-th lowercase letter of the Latin alphabet and write it either to the left of the string s or to the right of the string s (i.e. perform the assignment s := c+s or s := s+c, where c is the i-th letter of the Latin alphabet).
    In other words, iterate over the n first letters of the Latin alphabet starting from 'a' and etc. Each time we prepend a letter to the left of the string s or append a letter to the right of the string s. Strings that can be obtained in that way are alphabetical.

    For example, the following strings are alphabetical: "a", "ba", "ab", "bac" and "ihfcbadeg". The following strings are not alphabetical: "z", "aa", "ca", "acb", "xyz" and "ddcba".

    From the given string, determine if it is alphabetical.

TEST CASE:
        INPUT:
            11
            a
            ba
            ab
            bac
            ihfcbadeg
            z
            aa
            ca
            acb
            xyz
            ddcba
        OUTPUT:
            YES
            YES
            YES
            YES
            YES
            NO
            NO
            NO
            NO
            NO
            NO

*/
#include <bits/stdc++.h>
#define ll long int
#define vi vector
using namespace std;

int main()
{
    ll test;
    cin >> test;
    for (ll m = 0; m < test; m++)
    {
        string s;
        cin >> s;
        ll len = s.size();
        int apos = 0;
        deque<char> q;
        for (ll i = 0; i < len; i++)
        {
            char c = s[i];
            q.push_back(c);
        }
        int flag = 0;
        for (ll i = 0; i < len; i++)
        {
            if (q.front() == (96 + len - i))
            {
                q.pop_front();
            }
            else if (q.back() == (96 + len - i))
            {
                q.pop_back();
            }
            else
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}