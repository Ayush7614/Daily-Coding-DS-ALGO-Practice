// question link - https :codeforces.com/contest/1537/problem/D
// Alice and Bob are playing a game.
//     They start with a positive integer nn and take alternating turns doing operations on it.Each turn a player can subtract from nn one of its divisors that isn't 11 or nn. The player who cannot make a move on his/her turn loses. Alice always moves first.
//     Note that they subtract a divisor of the current number in each turn.
//     You are asked to find out who will win the game if both players play optimally.

// Testcase
// Input
// 1
// Output
// Bob

// Input
// 4
// Output
// Alice

// Input
// 12
// Output
// Alice

// Input
// 69
// Output
// Bob

// Template
#include <bits/stdc++.h>
#define fab(a, b, i) for (ll i = a; i < b; i++)
#define fba(b, a, i) for (ll i = b; i > a; i--)
#define pb push_back
#define po pop_back
#define P 1000000007
#define w(x)   ll x; cin >> x; while (x--)
#define fr first
#define sc second
#define en "\n"
#define all(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
#define sz size()
    using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

// Main code
int main()
{
    // fast input and output
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    w(t)
    {
        ll n;
        cin >> n;
        // if n is odd
        if (n & 1)
            cout << "Bob";
        // n is even
        else
        {
            // if n is a power of 2
            if (!(n & (n - 1)))
            {
                int c = 0;
                while (n)
                    n /= 2, c++;
                if (c & 1)
                    cout << "Alice";
                else
                    cout << "Bob";
            }
            // n is not a power of 2
            else
                cout << "Alice";
        }
        cout << en;
    }
}
