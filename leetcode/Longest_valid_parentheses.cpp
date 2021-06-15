//  32. Longest Valid Parentheses solution in cpp 
//  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// Input: s = ")()())"
// Output: 4
// Problem link: https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string S) {
        vector<int> stack = {-1};
        int ans = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '(') stack.push_back(i);
            else if (stack.size() == 1) stack[0] = i;
            else {
                stack.pop_back();
                ans = max(ans, i - stack.back());
            }
        return ans;
    }
};
