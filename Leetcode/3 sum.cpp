class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*------Naive approach -----
        Try all combination of triplets and return if sum 0
        for i=0 to n
         for j= i+1 to n
           for k=j+1 to n 
               s= nums[i]+nums[j]+nums[k];
              if s == 0
              result =reault[{nums[i],nums[j],nums[k]}](to get unique triplets we can store in              set)
              
              Complexity :O(n^3logm){log m->time taken to insert in set 
                                      n^3-> 3 loops} 
              ------better approach------
              Using hashing
              -------another approach-----------
              2 pointer approach
              ->sort array
              */
       int low,high,sum; 
        int n = size(nums);
        if(n<3)
        {
           return {}; 
        }
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            low=i+1;
            high=nums.size()-1;
            sum=0-nums[i];//set sum== -ve of the value so that we can check for its equality
            if(i==0||(i>0&&nums[i]!=nums[i-1])){  //if to remove duplicates other wise it can search for same sets again
                while(low<high){
                    vector<int>temp;
                    if(nums[low]+nums[high]==sum){//if the low and high sum up to sum
                        temp.push_back(nums[i]);//push them i temp vector
                         temp.push_back(nums[low]);
                         temp.push_back(nums[high]);
                         res.push_back(temp);//then push this temp into res vector
                        while(low<high && nums[low]==nums[low+1])low++;//to remove duplicacy we ignore the low and high iif they are equal to their previous values
                        while(low<high && nums[high]==nums[high-1])high--;
                    low++;
                    high--;
                        
                    }
                    else if(nums[low]+nums[high]<sum)low++;//if low+high < sum this means we have to increase the sum ----so we increament the low pointer as the vector is sorted so this increases sum
                    else {high--;}//>sum then we decreament the high pointer since array is sorted
                }
            }
     
    }
               return res;
}
};

/*----optimized code-----*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
       int low,high,sum; 
        int n = size(nums);
        if(n<3)
        {
           return {}; 
        }
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            low=i+1;
            high=n-1;
            sum=0-nums[i];
            if(i==0||(i>0&&nums[i]!=nums[i-1])){ 
                while(low<high){
                  
                    if(nums[low]+nums[high]==sum){
                         res.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1])low++;
                        while(low<high && nums[high]==nums[high-1])high--;
                    low++;
                    high--;
                        
                    }
                    else if(nums[low]+nums[high]<sum)low++;
                    else {high--;}
                }
            }
     
    }
               return res;
}
};
