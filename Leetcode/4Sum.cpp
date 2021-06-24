//link of the problem https://leetcode.com/problems/4sum/ 
//Solved in brute force as well as optimal solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
       // Brute Force Approach
//         vector<vector<int>> res;
//         sort(res.begin(),res.end());
//         int l=nums.size();
//         for(int i=0;i<l;i++)
//             for(int j=i+1;j<l;j++)
//                 for(int k=j+1;k<l;k++)
//                     for(int p=k+1;p<l;p++)
//                         if(nums[i]+nums[j]+nums[k]+nums[p]==target)
//                            { vector<int> v={nums[i],nums[j],nums[k],nums[p]};
//                            sort(v.begin(),v.end());
//                             if(find(res.begin(),res.end(),v)==res.end())
//                             res.push_back(v);}
        
//         return res;
       
        //Optimized Approach
        //taken vector of vector
         vector<vector<int>> res;
        //base case if the vector is empty
        if(nums.empty())
        {
            return res;
        }
        //size of num
        int n=nums.size();
        //done sorting
        sort(nums.begin(),nums.end());
        //traverse form the i to next j+1
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target_2=target-nums[j]-nums[i];
                //j+1 for right indices and n-1 to left 
                int front=j+1;
                int back=n-1;
                while(front<back)
                 {
                    int two_sum=nums[front]+nums[back];
                    //if two_sum<target_2 than front will be incremented or else back 
                    if(two_sum<target_2)front++;
                    else if(two_sum>target_2)back--;
                     else
                    {
                         //declaring 4 patches that will be always stored 
                        vector<int>ans(4,0);
                        ans[0]=nums[i];
                        ans[1]=nums[j];
                        ans[2]=nums[front];
                        ans[3]=nums[back];
                        res.push_back(ans);
                         //process for checking the duplication
                        while(front<back && nums[front]==ans[2])front++;
                        while(front<back && nums[back]==ans[3])back--;
                
            }
        }       
                    
         while(j+1<n && nums[j+1]==nums[j])j++;
    }
        while(i+1<n && nums[i+1]==nums[i])i++;
        
 }
        //return the vector
     return res;      
        
    }     
       
    
};


// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

        
