// Question  https://leetcode.com/problems/maximum-length-of-repeated-subarray/

import java.util.Scanner;

class Solution {
    public static int findLength(int[] A, int[] B) {
        int dp[][] = new int[A.length+1][B.length+1];
        int max = 0;
        for(int i = 0; i <= A.length; i++) {
            for(int j= 0; j <= B.length; j++) {
                if(i == 0 || j == 0 || A[i-1] != B[j-1]) dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max = Math.max(max, dp[i][j]);
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int alen = sc.nextInt();
        int blen = sc.nextInt();

        int[] A = new int[alen];
        for(int i = 0;i < alen;i++)
            A[i] = sc.nextInt();

        int[] B = new int[blen];
        for(int i = 0;i < alen;i++)
            B[i] = sc.nextInt();

        System.out.println( findLength(A, B) );
    }
}

//Example 1:
//        Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//        Output: 3
//        Explanation: The repeated subarray with maximum length is [3,2,1].
//
// Example 2:
//        Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//        Output: 5
