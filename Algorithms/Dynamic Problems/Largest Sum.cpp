// Largest Sum of Non-Adjacent Numbers
// Given a list of integers nums, write a function that 
// returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
// Input
// nums = [2, 4, 6, 2, 5]
// Output
// 13

// We can either include or excude i, if we include it our current sum will become maximum till
// i-2 and if we exclude it our current sum will be maximum till i-1 as we cant take adjacent elements.
int solve(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    // max sum til i-1 including it is stored in include 
    // max sum till i-1 excluding it is stored in exclude
    int include = max(0, nums[0]), exclude = 0;
    for (int i = 1; i < nums.size(); i++) {
        int temp = include;
        include = max(exclude + nums[i], include);
        exclude = temp;
    }
    return include;
}
