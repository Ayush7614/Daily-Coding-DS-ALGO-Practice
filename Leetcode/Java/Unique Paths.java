// Question https://leetcode.com/problems/unique-paths/

// Examples
/**
 * Example 1:
 * Input: m = 3, n = 7
 * Output: 28
 *
 * Example 2:
 * Input: m = 3, n = 2
 * Output: 3
 *
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 */

// Solution

import java.util.Scanner;

class Solution {
    public static int uniquePaths(int m, int n) {
        int smaller = m>n ? n-1 : m-1;
        int totalsteps = m+n-2;
        long result = 1;
        for (int counter = 1; counter<=smaller; counter++){
            result *= totalsteps--;
            result /= counter;
        }
        return (int)result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println( uniquePaths(m, n) );
    }
}