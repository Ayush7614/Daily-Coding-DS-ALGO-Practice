#include<bits/stdc++.h>
using namespace std;

 int dp[100][100];

int LCSTopDOwn(string s,string t,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][m];
    
}
main()
{
    string s = "heap";
    string t = "bea";
    memset(dp,-1,sizeof(dp));
    int lcs = LCSTopDOwn(s,t,s.length(),t.length());


    cout<<"--> deletion : ";
    cout<<s.length()-lcs;
    cout<<endl;
    cout<<"--> Insertion : ";
    cout<<t.length()-lcs;
    
}