"""
Problem:
"Roman to Integer" on LeetCode in Python, solution by monishamandal02

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

Input: str = "III"
Output: 3
Example 2:

Input: str = "IV"
Output: 4
Example 3:

Input: str = "IX"
Output: 9
Example 4:

Input: str = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: str = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

-- 1 <= str.length <= 15
-- str contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
-- It is guaranteed that str is a valid roman numeral in the range [1, 3999].
"""

def romanToInt(s: str) -> int:
    digits = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    length = len(s)
    v = digits[s[-1]];
    for i in range(1, length):
        if digits[s[i]] > digits[s[i - 1]]:
            v -= digits[s[i - 1]];
        else:
            v += digits[s[i - 1]];
    return v

if __name__ == '__main__':
    s=input()
    print(romanToInt(s))
