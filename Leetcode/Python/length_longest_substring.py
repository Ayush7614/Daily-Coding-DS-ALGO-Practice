"""
https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Example 4:
Input: s = ""
Output: 0
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        maximum_lengths = set()
        l = set()
        while i < len(s):
            if s[i] in l:
                l = set()
                maximum_lengths.add(i)
                index_same_el = s.index(s[i])
                s = s[index_same_el + 1:]
                i = 0

            else:
                l.add(s[i])
                i += 1
        maximum_lengths.add(i)
        return max(maximum_lengths)
