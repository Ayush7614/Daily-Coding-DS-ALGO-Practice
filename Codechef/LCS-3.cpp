/* Longest Common Subsequence(LCS) for 3 strings.
It is one of the most important question from competitve point of view.
To make it optimal I have used Dynamic Programming.
It can be done without DP also, but dp gives optimal solution.
*/

#include <bits/stdc++.h>

using namespace std;

int dp[205][205][205]; // Here 205 is the limit constraint.

int lcs(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if(i==0 || j==0 || k==0) //To check if string is empty
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
        return dp[i][j][k] = 1+lcs(s1,s2,s3,i-1,j-1,k-1);
    int l=lcs(s1, s2, s3, i-1, j, k);
    int r=lcs(s1, s2, s3, i, j-1, k);
    int p=lcs(s1, s2, s3, i, j, k-1);
    return dp[i][j][k] = max({l,r,p});
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s1,s2,s3;
    cout<<"Enter String 1: ";
    cin>>s1;
    cout<<"Enter String 2: ";
    cin>>s2;
    cout<<"Enter String 3: ";
    cin>>s3;
    cout<<"LCS is: ";
    cout<<lcs(s1,s2,s3,s1.size(),s2.size(),s3.size());
    return 0;
}

/*
Solution is ->
String 1: github
String 2: gitclone
String 3: forkgit
Lcs is: 3(git)
*/
