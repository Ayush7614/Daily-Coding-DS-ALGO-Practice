    
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
    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif



        int n;

        cin>>n;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        int lis[n];
        int dp[n];

        for(int i=0;i<n;i++) {
            dp[i]=1;
            lis[i]=1;
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]>a[j]) {

                    if(lis[i]<=lis[j]) {
                        lis[i]=lis[j]+1;
                        dp[i]=dp[j];
                    }

                    else if(lis[i]==lis[j]+1) {
                        dp[i]+=dp[j];
                    }

                }
            }
        }

        int y=*max_element(lis,lis+n);

        int c=0;

        for(int i=0;i<n;i++) {
            if(lis[i]==y) {
                c+=dp[i];
            }
        }

        cout<<c;


        return 0;
    }