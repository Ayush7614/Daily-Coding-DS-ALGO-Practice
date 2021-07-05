/*
Problem:
"Integer to Roman" on LeetCode, solution by AtrikGit6174

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string intToRoman(int num) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        string ret= "";
        string str= to_string (num);
        
        int pow= str.size()-1;
        
        for (int i=0; i<str.size(); i++, pow--)
        {
            switch (pow)
            {
                case 3:
                    switch(str[i])
                    {
                        case '3':
                            ret+="M";
                        case '2':
                            ret+="M";
                        case '1':
                            ret+="M";
                            break;                           
                    }
                    
                    break;
                    
                case 2:
                    switch(str[i])
                    {
                        case '0':
                            break;
                        case '9':
                            ret+="CM";
                            break;
                        case '8':
                            ret+="D";
                        case '3':
                            ret+="CCC";
                            break;
                        case '7':
                            ret+="D";
                        case '2':
                            ret+="CC";
                            break;
                        case '6':
                            ret+="D";
                        case '1':
                            ret+="C";
                            break;
                        case '5':
                            ret+="D";
                            break;
                        case '4':
                            ret+="CD";
                            break;                       
                               
                    }
                    
                    break;
                    
                case 1:
                    switch(str[i])
                    {
                        case '0':
                            break;
                        case '9':
                            ret+="XC";
                            break;
                        case '8':
                            ret+="L";
                        case '3':
                            ret+="XXX";
                            break;
                        case '7':
                            ret+="L";
                        case '2':
                            ret+="XX";
                            break;
                        case '6':
                            ret+="L";
                        case '1':
                            ret+="X";
                            break;
                        case '5':
                            ret+="L";
                            break;
                        case '4':
                            ret+="XL";
                            break;     
                    }
                    
                    break;
                    
                case 0:
                    switch(str[i])
                    {
                        case '0':
                            break;
                        case '9':
                            ret+="IX";
                            break;
                        case '8':
                            ret+="V";
                        case '3':
                            ret+="III";
                            break;
                        case '7':
                            ret+="V";
                        case '2':
                            ret+="II";
                            break;
                        case '6':
                            ret+="V";
                        case '1':
                            ret+="I";
                            break;
                        case '5':
                            ret+="V";
                            break;
                        case '4':
                            ret+="IV";
                            break;     
                    }
                    
                    break;
                    
            }
            
        }
        
        return ret;        
    }
};

int main()
{
    cout<<"Enter valid number [1-3999] to convert to Roman: ";
    int n; cin>>n;

    Solution *ob;
    cout<<"\nRoman numeral= "<<ob->intToRoman(n);
}
