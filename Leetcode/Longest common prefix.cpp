//Link to the problem
/*
  https://leetcode.com/problems/longest-common-prefix/
 */

//According to the problem:

//Given a array of strings.

//AIM: To find the longest common prefix string amongst an array of strings.If there is no common prefix, return an empty string "".


/*Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Input: strs = ["flower","flow","flight"]
Output: "fl"
since f1 is same in all
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string x="";//making a empty solution string
       //base case
        if(strs.size()==0)
            return x; 
        int i;
        //iterating over the 0th index string and comparig that with others
        for(i=0;i<strs[0].size();i++)
        {
            char t=strs[0][i];//1st char of 0th index string
            for(int j=1;j<strs.size();j++)//interating over remaining strings
            {
                if(t!=strs[j][i])//if character do not match
                    return x;//we can return the preiously matched string
            }
            x=x+t;//otherwise simplw we can the char to resultant string
        }
        return x;//returning the  longest common prefix string
    }
};