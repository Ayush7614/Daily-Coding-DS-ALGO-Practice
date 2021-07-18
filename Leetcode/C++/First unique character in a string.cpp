//Link to the problem
/*
  https://leetcode.com/problems/first-unique-character-in-a-string/
 */

//According to the problem:

//Given a string s
//AIM:, find the first non-repeating character in it and return its index. If it does not exist, return -1.

/*
 

Example 1:

Input: s = "leetcode"
Output: 0

*/
//SOLUTION:

class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,pair<int,int>>m;//map keeping the char and the pair of its freq and index number
        for(int x=0;x<s.size();x++)
        {
                m[s[x]].first++;//counting frequency
                m[s[x]].second=x;//inputing index
        }
        int ans=INT_MAX;
        for(auto x:m)
        {
            if(x.second.first==1)//checking for all unique char
                ans=min(ans,x.second.second);//finding the first unique char
        }
        if(ans!=INT_MAX)//returning ans
            return ans;
        return -1;//not found
    }
    
};