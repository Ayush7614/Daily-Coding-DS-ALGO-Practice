class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for (int i = 0 ; i < nums.length ; i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],1);
            }
            else{
                return true;
            }
        }
        return false;
    }
}

// Example test case
// Input: nums = [1,2,3,1]
// Output: true
//
// Input: nums = [1,2,3,4]
// Output: false
