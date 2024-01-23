#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

problem Link - https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
*/
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr,"",0,result);
        return result;
    }
    void dfs(const vector<string>&arr, const string& path,int idx,int &result){
       if(isuniquechars(path)){
           result = max(result,static_cast<int>(path.length()));
       }
       if(idx == arr.size()|| !isuniquechars(path)){
           return ;
       }
       for(int i = idx ; i<arr.size();i++){
           dfs(arr,path+arr[i],i+1,result);
       }
    }

    bool isuniquechars(const string& s){
        unordered_set<char> set;
        for(char c : s){
            if(set.count(c)){
                return false;
            }
            set.insert(c);
        }
        return true;
    }
};