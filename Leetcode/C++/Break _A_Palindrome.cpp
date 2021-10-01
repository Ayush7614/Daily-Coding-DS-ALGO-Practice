//1328. Break a Palindrome

/*Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.
*/


/*
Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        //Not possible to make replacement when length is 0 or 1
        if(n == 0 || n == 1)
            return "";
        for(int i=0; i<n; i++){
            //Change the first non 'a' character to 'a'
            if(palindrome[i] != 'a'){
                if (!(n%2 != 0 && i == n/2))
                    return palindrome.substr(0, i) + 'a' + palindrome.substr(i+1);
            }
        }
        //Change the last character to 'b'
        return palindrome.substr(0, n-1) + 'b';
    }
};


// This code is contributed by Nikhil-1503.
