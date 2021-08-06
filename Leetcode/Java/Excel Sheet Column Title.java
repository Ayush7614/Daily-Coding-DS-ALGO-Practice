// Question  https://leetcode.com/problems/excel-sheet-column-title/

// Examples
/**
 * Example 1:
 * Input: columnNumber = 1
 * Output: "A"
 * 
 * Example 2:
 * Input: columnNumber = 28
 * Output: "AB"
 * 
 * Example 3:
 * Input: columnNumber = 701
 * Output: "ZY"
 */

// Solution

import java.util.Scanner;

class Solution {

    static char[] arr = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    public static String convertToTitle(int columnNumber) {

        String ch = "";
        while(columnNumber > 0){
            columnNumber--;
            ch += arr[columnNumber%26];
            columnNumber /= 26;
        }

        StringBuilder ch1 = new StringBuilder();
        ch1.append(ch);
        ch1.reverse();
        return ch1.toString();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int columnNumber = sc.nextInt();

        System.out.println( convertToTitle(columnNumber) );
    }
}
