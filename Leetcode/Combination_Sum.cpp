
class Solution {
public:
    
    void helper(vector<int> &candidates,int target,vector<vector<int>> &res,
                                            vector<int> &combination,int begin)
    {
        if(!target)
        {
            res.push_back(combination);  // if target is 0 add to resultant vector
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];++i) 
        {
            combination.push_back(candidates[i]);
            helper(candidates,target-candidates[i],res,combination,i);  // unlimited times
            combination.pop_back();                                     // backtrack
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());    // sort 
        vector<vector<int>>res;                       // resultant vector
        vector<int>combination;                       // trying combinations
        
        helper(candidates,target,res,combination,0);
        return res;
        
    }
};

