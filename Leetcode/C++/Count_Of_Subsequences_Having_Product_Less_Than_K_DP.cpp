    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    int max_count(int a[],int n,int k) {


        int dp[n+1][k+1];

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++) {

            for(int j=1;j<=k;j++) {

                dp[i][j]+=dp[i-1][j];

                if(a[i-1]<=j&&a[i-1]>0) {
                    dp[i][j]+=dp[i-1][j/a[i-1]]+1;
                }
            }

        }

        return dp[n][k];
    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int n,k;

        cin>>n>>k;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        cout<<max_count(a,n,k);


        return 0;
    }