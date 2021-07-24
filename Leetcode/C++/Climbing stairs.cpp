//LINK TO THE QUESTION: https://leetcode.com/problems/climbing-stairs/
/*
QUESTION STATEMENT:
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//AIM: To calculate the distinct ways can user climb to the top.

//Example:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
#include<iostream>
using namespace std;

    int climbStairs(int n) {
        int ans;
        int dp[n+1];
        
       dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
           dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
int main()
{
    int n;
    cin>>n;
    int ans=climbChairs(n);
    cout<<ans;
    return 0;
}