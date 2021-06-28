/*
Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

    Input:
        First line of input contains a single integer T, the number of test cases.
        Each test is a single line containing a string S composed of only lowercase English alphabet.
    Output:
        For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.
    Constraints:
        1 ≤ T ≤ 100
        2 ≤ |S| ≤ 1000, where |S| denotes the length of S

    Example:
    Input:

        6
        gaga
        abcde
        rotor
        xyzxy
        abbaab
        ababc


    Output:

        YES
        NO
        YES
        YES
        NO
        NO

 */
//-------------------------------------Solution--------------------------------------------------

				//by one counter array approach


/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
      //maximum character
       static final int MAX_CHAR = 26;
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
        while(testCases > 0){
            //we have to take the string object to take input as a character
            String str = new String();
            str = sc.next();
            //if user input is lapindrome then it will print yes or it will print no.
            if(isLapindrome(str) == true) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            testCases--;
        }
    }

    public static boolean isLapindrome(String str){
        //we have to taken only the one character array of size 26
        int[] count = new int[MAX_CHAR];
        int n = str.length();
        //we have to iterate the ith loop from 0 to n/2(from left to right)
        //and  jth loop from n-1 to n/2(from right to left)
        for(int i = 0, j = n-1; i < n/2; i++, j--){
            count[str.charAt(i) - 'a']++;
            count[str.charAt(j) - 'a']--;
        }
        //we iterate the loop from 0th index to last index in the array then it will check
        //if the count of ith index is not equal to zero the it will return as false 
	    //or it will return true
        for(int i = 0; i < MAX_CHAR; i++){
            if(count[i] != 0) {
                return false;
            }
        }
        return true;
    }

}
