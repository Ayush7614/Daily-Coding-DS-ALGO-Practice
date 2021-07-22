class Solution {
public:
    int combinationSum4(vector<int>& a, int t) 
    {
        long dp[t+1];// maintain an array inorder to store previous results
                     // for eg. dp[1] means number of ways encountered till now to obtain 1 as the total sum
        dp[0]=1;   // set dp[0] as 1 
        for(int i=1;i<=t;i++)
        {
            dp[i]=0;// initially number of ways to get i as sum is 0
           for(int j=0;j<a.size();j++) // iterate through array to check if it is possible to get i as sum or not
           {
                if(dp[i]>INT_MAX)break; //ensures it is a 32-bit integer
               if(i-a[j]<0)
                   continue;     // if not possible continue with other element of array
               else if(dp[i-a[j]]!=0)
                   dp[i]+=dp[i-a[j]]; //if possible add number of ways
             
           }
        }
        return dp[t];  // retur dp[t] as it stores all the numbetr of ways to obtain t as sum
    }
};

//Time Complexity: O(t*size of array)
//Space Complexity: O(t)