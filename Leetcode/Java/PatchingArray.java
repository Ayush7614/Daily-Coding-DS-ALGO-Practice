/*Problem Number on leetcode: 330

Problem name: Patching Array(Hard)

Problem statement: Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
Return the minimum number of patches required.

Example 1:
Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
*/

class PatchingArray {
    public int minPatches(int[] nums, int n) {
    int count = 0, i = 0;
    long priorSum = 0;
    while(priorSum<n) {
        if(i>=nums.length || nums[i]>priorSum+1) {
            ++count;
            priorSum = (priorSum<<1) + 1;
        }
        else priorSum += nums[i++];
    }
    return count;
}
}

