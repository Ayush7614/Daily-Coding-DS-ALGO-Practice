// Solution for Maximum sum removing K numbers from Ends
// You are given a list of integers nums and integer k. 
// Return the maximum sum of elements that you can remove given that you must pop exactly k times, 
// where each pop can be from the left or the right end.
// Input
// nums = [1, 3, 4, 2, 0]
// k = 2
// Output
// 4

int solve(vector<int>& nums, int k) {
    // accumulate calculates the total sum starting from nums->begin to the end of the vector
    // and the initial value of total is zero.
    int total = accumulate(nums.begin(), nums.end(), 0);
    // As we are given to remove k elements from the list, So we will find minimum sum of 
    // a sublist of size nums.size()-k.
    k = nums.size() - k;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        cur += nums[i];
    }
    int res = cur;
    // After finding the minimum sum we will substract it from the total sum.
    for (int i = k; i < nums.size(); ++i) {
        cur -= nums[i - k];
        cur += nums[i];
        res = min(res, cur);
    }
    return total - res;
}