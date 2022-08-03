class Solution {
public:
    vector<int> preSum;
    int sz;
    int dp[1001][51];
    int fun(int l,int m){
        if(dp[l][m]!=-1) return dp[l][m];
        int ans=INT_MAX;
        if(m==1)
            return dp[l][m]=preSum[sz]-preSum[l];
        for(int i=l;i<sz and i<sz-m+1;i++)
            ans=min(ans,max(preSum[i+1]-preSum[l],fun(i+1,m-1)));
        
        return dp[l][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        preSum.push_back(0);
        sz=nums.size();
        for(auto n:nums)
            preSum.push_back(preSum.back()+n);
        return fun(0,m);
    }
};
