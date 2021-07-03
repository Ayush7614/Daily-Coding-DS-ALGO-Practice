//The following is C++ program to approximate number of people for a given probability.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(double probabilty)
{
    return ceil(sqrt(2 * 365 * log(1 / (1 - probabilty))));
}
int main()
{
    int t = 1;
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    //cin>>t;
    while (t--)
    {
        cout << solve(0.7) << "\n"; //Probality  assumed to be 0.7 
    }
}
//Output : 30
