/*
 Problem : We are given a gold mine of n*m dimensions.
 Each field in mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

 1. to the cell diagonally up towards the right 
 2. to the right
 3. to the cell diagonally down towards the right
 we need to find out maximum amount of gold which he can collect.

 Sample I/p : 4 4
              1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
 Sample O/P : 16
 */

 #include <bits/stdc++.h>
 using namespace std;

 int maxGold(int n, int m, vector<vector<int> > gold_mine) {
         int ans = INT_MIN;
         vector<vector<int> > dp(n+2, vector<int> (m+1, 0));
         for(int j = 1;  j <= m; j++){
             for(int i = 1; i <= n; i++){
                 dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1])) + gold_mine[i-1][j-1];
             }
         }

         for(int i = 0;i <= n;i++)
             ans = max(dp[i][m], ans);

         return ans;
 }

 int main() {
     int m,n;
     cin >> n >> m;
     vector<vector<int> > gold_mine(n, vector<int>(m, 0));
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             cin >> gold_mine[i][j];
         }
     }

     cout<< maxGold(n, m, gold_mine) <<"\n";
     return 0;

 } 