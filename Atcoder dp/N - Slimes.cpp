
//https://atcoder.jp/contests/dp/tasks/dp_n
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

ll dp[3001][3001];
ll sum[3001][3001];//taking a dp

ll solve(vector<int>& v, int i, int j)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll minCost = inf;
    for(int k = i; k < j; k++)
    {
            minCost = min(minCost, sum[i][j] + solve(v, i, k) + solve(v, k + 1, j));// solving for i to k and then i+1 to j
    }
    return dp[i][j] = minCost;
}

void preprocess(vector<int>& v, int n)
{
    for(int i = 1; i  <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j-1]);
        }
    }
}
int main() {
   int n;
   cin >> n ;
   memset(dp, -1, sizeof dp);
   vector<int> v(n+1);
   for(int i = 1; i <= n; i++)
        cin>>v[i];
    preprocess(v,n);
   cout<<solve(v, 1, n);
   return 0;
}
