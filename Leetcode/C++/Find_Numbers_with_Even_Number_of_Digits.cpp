/* Easy
1295. Find Numbers with Even Number of Digits
Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

Statement: 
Given an array nums of integers, return how many of them contain an even number
of digits.

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
*/

/*
Explanation
Suppose that n has d digits; then 10^d−1 <= n < 10^d, because 10^d is the
smallest integer with d+1 digits. Taking logs base 10: log10(10k) = k, so the 
inequality becomes d−1 <= log10(n) < d. On taking the floor of log10(n), 
floor(log10(n)) = d−1.
Thus the floor of log bases 10 of number containing even number of digits
would be odd.
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int x = log10(nums[i]);
            if(x&1)
            ans++;
        }
        return ans;
    }
};