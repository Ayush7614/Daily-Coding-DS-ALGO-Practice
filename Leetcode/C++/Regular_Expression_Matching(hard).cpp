
// Regular Expression Matching (Hard ) probem of LeetCode

/*

# First test case
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

# Second test case
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

*/

# include<bits/stdc++.h>
using namespace std;

//class solution
class Solution {
public:
    bool match_recur(string &s, string &p, int i , int j) 
    {
        if(i<0)             
        {
            if(j<0)//complete string and patt matched
                return true;
            else if( p[j]=='*') //check if pattern has only x* statements remaining
                return match_recur(s,p,i,j-2);
            else
                return false;//string ended but pattern still remains
        }
        else if(j<0)//pattern ended string remains
            return false;
            
        if(p[j]=='.' || s[i]==p[j])//. or pattern char and string char are same
            return match_recur(s,p,i-1,j-1);    

        else if(p[j]=='*')
        {
            if((s[i]==p[j-1] || p[j-1]=='.') && match_recur(s,p,i-1,j))//select * pattern
                return true;
            return match_recur(s,p,i,j-2);//don't select * pattern
        }
                
                
        return false;   //current char in str doesn't match current patt
    }
    
    // matching dp function
    bool match_dp(string &s, string &p)
    {
    	// created m and n variable
        int m=s.size(),n=p.size();
        
        // created a dp 2D array
        bool dp[m+1][n+1];
        dp[0][0]=true;
        
        // Initialized the dp array
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        for(int i=1;i<=n;i++)
            if(p[i-1]=='*')
                dp[0][i] = dp[0][i-2];
            else
                dp[0][i]=false;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')       
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    if(dp[i][j-2])//not selecting * matches pattern
                        dp[i][j]=true;
                    else if(s[i-1]==p[j-2] || p[j-2]=='.')//x in x*  matches previous char or previous char is '.'
                        dp[i][j] = dp[i-1][j];  
                    else
                        dp[i][j]=false;     
                }
                else
                    dp[i][j]=false;
                //cout<<dp[i][j];
            }  
            //cout<<"\n";
        }
        return dp[m][n];  
    }
    bool isMatch(string s, string p) {
        return match_recur(s,p, s.size()-1 , p.size()-1);
    }
};

int main()
{
	string s,p;
	cin>>s>>p;
	
	Solution *obj = new Solution();
	if(obj->isMatch(s,p))
		cout<<"True";
	else
		cout<<"False";
	
	return 0;
}
