//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void backtrack(vector<string>& ans,int open,int close,string s,int n){
        if(s.length()==2*n){ 
            ans.push_back(s);
            return;
        }
        if(open<n) backtrack(ans,open+1,close,s+'(',n);
        if(close<open) backtrack(ans,open,close+1,s+')',n);
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        backtrack(ans,0,0,"",n);
        return ans;
        // Your code goes here 
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends