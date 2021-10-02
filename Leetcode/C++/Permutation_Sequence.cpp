/** Problem Statement https://leetcode.com/problems/permutation-sequence/

Approach: Using recursion calculate first index of permutation each time and 
continue for all permutations then return the kth permutation at end **/


class Solution {
public:
    string s = "";
    void solve(vector<int>&nums, int n, int k){
        if(n == 1){
            s += nums[0]+ '0';
            return ;
        }
        // calculating index , add int index to string erase digit, new k, n
        int idx = k / fac[n-1];
        if(k%fac[n-1] == 0){
            idx -= 1;
        }
        s += nums[idx] + '0';
        nums.erase(nums.begin()+idx);
        k -= idx * fac[n-1];
        solve(nums, n-1, k);
        
    }
    int fac[10] = {1,1,2,6,24,120, 720, 5040, 40320, 362880}; // factorials of first 10 numbers
    string getPermutation(int n, int k){
         vector<int>nums;
         for(int i = 0; i < n; i++){
             nums.push_back(i+1);
         }
         solve(nums, n, k);
        return s;
           
    }
};

