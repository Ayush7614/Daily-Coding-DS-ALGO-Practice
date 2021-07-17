//Link to the problem
/*
https://leetcode.com/problems/reorganize-string/                                        
*/

//According to the problem:

//Given a string s, we have to rearrange the characters of s so that any two adjacent characters are not the same.

//AIM:  Return any possible rearrangement of s or return "" if not possible.

/*Sample Example :
Input: s = "aab"
Output: "aba"
*/

class Solution {
public:
    //Function to get the character with maximum count
      char getMaxCountChar(const vector<int>& counter)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (counter[i] > max) {
            max = counter[i];
            ch = 'a' + i;
        }
    }
 
    return ch;//char with max count
}
    string reorganizeString(string str) {
   
        int n = str.size(); //stores size of string
    if (!n)                 //  Not possible case
        return "";
 
    vector<int> counter(26, 0);   //keeping track of frequencies
    for (auto ch : str)
        counter[ch - 'a']++;    //updating count
 
    char ch_max = getMaxCountChar(counter); //calling getMaxCountChar
    int maxCount = counter[ch_max - 'a']; //maximum count 
 
    // checking if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";//not possible case
 
    string res(n, ' ');
 
    int ind = 0;
    // filling the most frequently occuring char in the even indices 
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    counter[ch_max - 'a'] = 0; //filled all freq of maxcount
 
    // now filling the other Chars, first filling the even positions and then the left ones at odd positions
    for (int i = 0; i < 26; i++) {
        while (counter[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            counter[i]--;
        }
    }
    return res;
        //characters of s in res are added now so that any two adjacent characters are not the same
    }
};