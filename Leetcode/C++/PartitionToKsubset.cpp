/*Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int num:nums)
        {
            total+=num;
        }
        if(total%k!=0)
        {
            return false;
        }
        if(nums.size()<k)
            return false;
        int subsetsum=total/k;
        vector<bool>visited(nums.size(),false);
        return canpartition(nums,visited,0,k,0,subsetsum);
            
        
        
    }
    private:
    bool canpartition(vector<int>&nums,vector<bool>&visited,int start,int k,int currsum,int subsetsum)
    {
        // base  case
        if(k==0)
            return true;
        if(currsum>subsetsum)
            return false;
        if(currsum==subsetsum)
            return canpartition(nums,visited,0,k-1,0,subsetsum);
        for(int i=start;i<nums.size();i++)
        {
            if(visited[i])
                continue;
            visited[i]=true;
            if(canpartition(nums,visited,i+1,k,currsum+nums[i],subsetsum))
                return true;
            visited[i]=false;
            
        }
        return false;
    }
};