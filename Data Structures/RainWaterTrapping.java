
/* 
Problem Statement : Given n non-negative integers representing
an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
LeetCode Question Number 42

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
import java.util.*;

public class RainWaterTrapping {

    // maximum water trapped
    public static int maxWater(int building[], int n) {

        int res = 0;

        for (int i = 1; i < n - 1; i++) {

            // Find maximum element on left of building
            int left = building[i];
            for (int j = 0; j < i; j++) {
                left = Math.max(left, building[j]);
            }

            // Find maximum element on right of building
            int right = building[i];
            for (int j = i + 1; j < n; j++) {
                right = Math.max(right, building[j]);
            }

            // Update maximum water value
            res += Math.min(left, right) - building[i];
        }
        return res;
    }

    // main
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n;
        System.out.println("Enter length of the array");
        n = scn.nextInt();
        int building[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter elememts of array");
            building[i] = scn.nextInt();
        }

        int waterStored = maxWater(building, n);
        System.out.print("Water trapped due to rain is " + waterStored);
    }
}
