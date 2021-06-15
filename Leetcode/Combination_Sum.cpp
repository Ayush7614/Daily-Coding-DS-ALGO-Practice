class Solution {
public:
    
    void helper(vector<int> &candidates,int target,vector<vector<int>> &res,
                                            vector<int> &combination,int begin)
    {
        if(!target)
        {
            res.push_back(combination);
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];++i)
        {
            combination.push_back(candidates[i]);
            helper(candidates,target-candidates[i],res,combination,i);
            combination.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>combination;
        
        helper(candidates,target,res,combination,0);
        return res;
        
    }
};
