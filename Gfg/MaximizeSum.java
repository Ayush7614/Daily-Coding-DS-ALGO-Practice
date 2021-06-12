/*
Question 

Maximize the sum of selected numbers from an array to make it empty.
Given a sorted array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists), and Ai each from the array. Repeat these steps until the array gets empty. The problem is to maximize the sum of the selected numbers.

Example 1:
Input : arr[ ] = {1, 2, 3}
Output :  4

Example 1:
Input : arr[ ] = {1, 2, 2, 2, 3, 4}
Output : 10

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
Note: Numbers need to be selected from maximum to minimum.
*/


// Solution


import java.util.*; 
import java.math.*;
  
class MaximizeSum { 
  
    static int getMaximumSum(int []arr) { 
        int n = arr.length;
      
        int max = -1;
        for(int i = 0; i < n; i++){
            max = Math.max(max, arr[i]);
        }
          
        int ans[] = new int[max + 1];
          
        for(int i = 0; i < n; i++){
            ans[arr[i]]++;
        }
          
        for(int i = 2; i <= max; i++){
            ans[i] = Math.max(ans[i - 1], ans[i - 2] + i* ans[i]);
        }
          
        return ans[max];
          
    } 
      
    // Driver code 
    public static void main(String[] args) { 
        int a[] = {1, 2, 2, 2, 3, 4};
        System.out.println(getMaximumSum(a)); 
    } 
} 

// Time Complexity: O(n)
// Space Complexity: O(n)
