// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int countWays(string S1, string S2){
        
        int n=S1.size();
        int m=S2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n+1;i++) {
            dp[i][0]=1;
        }
        
        for(int j=0;j<m+1;j++) {
            dp[0][j]=0;
        }
        
        dp[0][0]=1;
        
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(S1[i-1]==S2[j-1]) {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
        
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends