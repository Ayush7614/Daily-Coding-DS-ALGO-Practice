/*
Problem:
"Roman to Integer" on LeetCode, solution by AtrikGit6174

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
*/

#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    int romanToInt(string str) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int ret= 0;
        int n= str.size();
        for (int i=n-1; i>=0; i--)
        {
            switch (str[i])
            {
                case 'I':
                    if (i+1<n and (str[i+1]=='V' or str[i+1]=='X'))
                    {
                        ret-= 1;
                        break;
                    }
                    ret+= 1;
                    break;
                
                case 'V':
                    ret+= 5;
                    break;
                
                case 'X':
                    if (i+1<n and (str[i+1]=='L' or str[i+1]=='C'))
                    {
                        ret-= 10;
                        break;
                    }
                    ret+= 10;
                    break;
                
                case 'L':
                    ret+= 50;
                    break;
                
                case 'C':
                    if (i+1<n and (str[i+1]=='D' or str[i+1]=='M'))
                    {
                        ret-= 100;
                        break;

                    }
                    ret+= 100;
                    break;
                
                case 'D':
                    ret+= 500;
                    break;
                
                case 'M':
                    ret+= 1000;
                    break;         
            }
        }
        
        return ret;
    }
};

int main ()
{
    cout<<"Enter Roman numeral string: ";
    string str; cin>>str;

    Solution *ob;
    cout<<"\nInteger= "<<ob->romanToInt(str);

    return 0;
}