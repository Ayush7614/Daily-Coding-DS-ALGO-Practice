#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 #define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
 #define INF 1000000000000000000
#define inf 1000000000
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
void solve()
{    
    ll n, m, k;
    cin >> n >> m >> k;
    ll x[n*m+1],y[n*m+1];
    rep(i,n*m)cin>>x[i+1]>>y[i+1];   
    ll left = 1, right = n*m;
    string ans = "Draw";
    ll steps=INF;
    ll mul = (n+2)*(m+2);
    while(left<=right){
        ll mid = (left+right)/2;
        vector<vector<int>>status(n+5, vector<int>(m+5,0));
        for(int i=1;i<=mid;i++){
            if(i&1)status[x[i]][y[i]]=1;
            else status[x[i]][y[i]]=2;
        }
        ll fn = 0;
        vvi col(n+2, vi(m+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(status[i][j]==1)col[i][j]=col[i+1][j]+1;
                else col[i][j]=0;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(col[i][j]>=k)col[i][j]=col[i][j+1]+1;
                else col[i][j]=0;
                if(col[i][j]>=k)fn=1;
            }
        }
        col.clear();
        col.resize(n+2, vi(m+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(status[i][j]==2)col[i][j]=col[i+1][j]+1;
                else col[i][j]=0;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(col[i][j]>=k)col[i][j]=col[i][j+1]+1;
                else col[i][j]=0;
                if(col[i][j]>=k)fn=2;
            }
        }
        if(fn==0){
            left=mid+1;
        }else{
            if(mid<steps){
                steps=mid;
                if(fn==1)ans="Alice";
                else ans="Bob";
            }
            right=mid-1;
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
 
  fastio
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin>>t;
    while(t--)
    {
     solve();
    }
}