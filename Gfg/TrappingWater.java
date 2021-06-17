/*
Problem Statement : Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.
LeetCode Question Number 42

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
*/

import java.io.*;

class TrappingWater {

    // function to return maximum water
    public static int maxWater(int building[], int n) {

        // Maximum water stored
        int res = 0;

        for (int i = 1; i < n - 1; i++) {

            // Find maximum element on left
            int left = building[i];
            for (int j = 0; j < i; j++) {
                left = Math.max(left, building[j]);
            }

            // Find maximum element on right
            int right = building[i];
            for (int j = i + 1; j < n; j++) {
                right = Math.max(right, building[j]);
            }

            // adding the maximum water
            res = res + Math.min(left, right) - building[i];
        }
        return res;
    }

    public static void main(String[] args) {

        int building[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        int n = building.length;

        System.out.print(maxWater(building, n));
    }
}
