// Question 

// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Example 4:
// Input: s = ""
// Output: 0 

// *****************************************************************************************************

// Constraints /  function:

// 0 <= s.length <= 5 * 10^4
// s consists of  letters, digits, symbols and spaces.

// *****************************************************************************************************


// Solution
import java.lang.*;
import java.io.*;
import java.util.*;
public class Longest_Substring {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        int ans=0;
        Map<Character,Integer> map = new HashMap<>();
        for(int j=0, i=0; j<len; j++){
            if(map.containsKey(s.charAt(j)))
                i = max(map.get(s.charAt(j)), i);
            ans = max(ans, j-i+1);
            map.put(s.charAt(j), j+1);
        }
        return ans;
    }   
}

// Driver code
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int answer = (new Longest_Substring()).lengthOfLongestSubstring(sc.nextLine());
    System.out.print(answer);
  }
}

// Time Complexity = O(n)
// Space Complexity = O(n)
