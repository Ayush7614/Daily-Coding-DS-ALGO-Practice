//https://atcoder.jp/contests/dp/tasks/dp_x
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x 
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[1001][10001];
struct box
{
    int si;
    int wi;
    ll val;
};

bool comp(box& b1, box& b2)
{
    return b1.si + b1.wi > b2.si + b2.wi;
}

ll solve(vector<box>& v)
{
    int n = v.size();
    sort(v.begin(), v.end(), comp);
    for(int j = 0; j <= 10000; j++)
    {
        if(v[0].si >= j)
            dp[0][j] = v[0].val;
        else dp[0][j] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            ll op1 = dp[i-1][j];
            ll op2 = (v[i].si >= j) ? (v[i].val + ((j + v[i].wi > 10000)?0:dp[i-1][j+v[i].wi])) : 0;
            dp[i][j] = max(op1, op2);
        }
    }
    return dp[n-1][0];
}

int main() {
   int n;
   cin >> n;
   vector<box> v(n);
   for(int i = 0; i < n; i++)
        cin >> v[i].wi >> v[i].si >> v[i].val;
   cout << solve(v);
   return 0;
}
