//Here is the link to solve the whole problem.Solved in Brute Force as well as optimised the code .
//https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        //storing the counters
        int c=0;
        int j=mid+1;
        //Traversing from low to mid 
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]> 2LL*nums[j])
            {
                j++;
            }
            c+=(j-(mid+1));
            
        }
        //creting dumby temp to store 
        vector<int>temp;
        int left=low,right=mid+1;
        
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
                
            }
        }
        
            
        //left will be small than left will  be incremented by one
        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }
               //right will be small than left will  be incremented by one
 
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }
           // Traversing form low to high

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
        //return no of count
        return c;
        
    }
    int mergeSort(vector<int>&nums,int low,int high)
    {
        if(low>=high)
        {
            return 0;
        }
        //finding the mid
        int mid= (low +high)/2;
        //caling mergeSort for the left half
      int inv=  mergeSort(nums,low,mid);
        //calling mergeSort for the right half
        inv += mergeSort(nums,mid+1,high);
        //combinig all together
        inv+=merge(nums,low,mid,high);
        return inv;
        
        
    }
    int reversePairs(vector<int>& nums) {
        //brute force approach
//         int c=0;
//         for(int i=0;i<nums.size();i++)
//         {
//            for(int j=i+1;j<nums.size();j++)
//            {
//                if(nums[i] > 2 * nums[j])
//                {
//                    c++;
//                }
//            }
//         }
//         return c;
    return mergeSort(nums,0,nums.size()-1);
        
    }
};
// Input: nums = [1,3,2,3,1]
// Output: 2


// Input: nums = [2,4,3,5,1]
// Output: 3

