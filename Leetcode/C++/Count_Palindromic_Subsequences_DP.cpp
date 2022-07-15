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

    string s;

    int dp[1001][1001];

    int cntPalin(int i,int j) {

        if(i>j) {
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        if(i==j) {
            return dp[i][j]=1;
        }

        else if(s[i]==s[j]) {
            return dp[i][j]=cntPalin(i+1,j)+cntPalin(i,j-1)+1;
        }
        else {
            return dp[i][j]=cntPalin(i+1,j)+cntPalin(i,j-1)-cntPalin(i+1,j-1);
        }

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        memset(dp,-1,sizeof(dp));

        cin>>s;


        cout<<cntPalin(0,s.size()-1);


        return 0;
    }