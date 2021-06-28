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
				//by two counter array approach

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		while(testCases --> 0){
		    //we have to take the string object to take input as a character
		    String str = new String();
		    str = sc.next();
		    int len = str.length();
		    int[] left = new int[26];
		    int[] right = new int[26];
		    	
			//we have taken left array to iterate through 0th to mid(len/2) index
		        for(int i = 0;i<len/2;i++){
		            left[str.charAt(i) - 'a']++;
		        }

		        //we have taken right array to iterate throught len+1/2(mid+1) to last index
		        for(int i = (len+1)/2;i<len;i++){
		            right[str.charAt(i) - 'a']++;
		        }

		        boolean flag = true;
			//we iterate the array from left to right to check if left is not equal to
			// right then it will return false or it will return true
		        for(int i = 0;i<26;i++){
		            if(left[i] != right[i])
		              flag = false;
		        }

		    if(flag == true)
		        System.out.println("YES");
		    else
		        System.out.println("NO");
		}
	}
}
