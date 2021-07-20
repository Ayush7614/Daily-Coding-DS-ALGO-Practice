//Link to the problem
/*
   https://leetcode.com/problems/permutation-in-string/
 */

//According to the problem:

//Given two strings s1 and s2

//AIM:  Return true if s2 contains the permutation of s1.

/*
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //Base Case
           if (s2.length() < s1.length()) {
            return false;
        }
        
        // vector to store the frequencies of chars in s1
        // As the input string contains only lower case letters
        vector<int> s1freq(26, 0);
        // vector to store the frequencies of chars in s2 for the first k
        // chars of s2 where k is the length of s1
        vector<int> s2freq(26, 0);

        
        // Filling the frequencies of all the chars in s1
        // Filling the freq of s2 ie.. max of k chars
        for (int i = 0; i < s1.length(); i++) {
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        }
        
        // Initializing the Window variables, window size is s1.length
        int Start = 0;
        int End = s1.length();
        
        // Traverse the window while all chars of s2 are done
        while (End < s2.length()) {
            // Check the frequencies of s1 and the curr windows of s2 are equal
            if (s1freq == s2freq) {
                // A permutation of s1 is availale in s2, returning true
                return true;
            }
            
            // Update the freq of the chars at start and end
            s2freq[s2[End] - 'a']++;
            s2freq[s2[Start] - 'a']--;
            
            // Move the window
            Start++;
            End++;
        }
        
        // Cornor case when the permutation of s1 is available at the end of s2,
        // checking the frequencies of s1 and s2
        return s1freq == s2freq;
    }
    
};