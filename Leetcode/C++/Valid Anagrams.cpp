//Link of question:
//https://leetcode.com/problems/valid-anagram/

//Given:Given two strings s and t, 

//AIM: Return true if t is an anagram of s, and false

//Example:

/*Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(size(s)!=size(t))
            //Size of both strings needs to be same
            return false;
        unordered_map<char,int>m;
        for(auto i:s)
            //maintaining freq of each char in string 1
            m[i]++;
        for(auto i:t)
            //decrementing the freq of string1 if encountered in 2
            m[i]--;
        for(auto x:m)
        {
               if(x.second!=0)
                   //if ans is not 0 that means they have diff char which is not possible for anagrams
            return false;
        }
     return true;//true if anagrams
    }
};