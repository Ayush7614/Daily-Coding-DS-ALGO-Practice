/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, 
such that the container contains the most water.

Notice that you may not slant the container.


Example:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/

// Solution:

/*
    Our main idea revolves around the following points:

    1. The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
    2. All other containers are less wide and thus would need a higher water level in order to hold more water.
    3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
*/

class Solution {
    public int maxArea(int[] height) {
        //setting low, high and maximum.
        int lo = 0;
        int hi = height.length - 1;
        int max = 0;
        
         while(lo <= hi){
             /* here, the maximum water stored between two towers of different heights, will be the difference between them multiplied by the minimum height of the two towers
             given. */
             max = Math.max(max, ((hi - lo) * Math.min(height[lo], height[hi])));
             if(height[lo] < height[hi]){
                 lo++;
             }else{
                 hi--;
             }
         }
        return max;
    }
}
