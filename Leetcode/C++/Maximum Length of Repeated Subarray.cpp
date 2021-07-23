class Solution {
public:
   int findLength(vector<int>& text1, vector<int>& text2) 
    {
        int m = text1.size();
        int n = text2.size();
        int res = 0;
        
        int t[m + 1][n + 1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(text1[i - 1] == text2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = 0; 
                
                res = max(res, t[i][j]);
            }
        }
       return res;
        
    }
};
