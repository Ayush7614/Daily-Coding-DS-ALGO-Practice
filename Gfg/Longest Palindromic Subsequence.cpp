#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int LCS(string s,string b){
        int n=s.length();
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                 }
        //     }
        // }
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<n+1;j++){
                else if(s[i-1]==b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][n];
    }
    
    int longestPalindromeSubseq(string s) {
        
        string b=s;
        reverse(b.begin(),b.end());
        
        return LCS(s,b);
        
        
        
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	  string s;
    cin>>s;

    Solution obj;
    int ans=obj.longestPalindromeSubseq(s);
    cout<<ans<<endl;
    return 0;
}
