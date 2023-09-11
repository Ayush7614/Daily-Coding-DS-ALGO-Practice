/*Problem Number on leetcode: 43

Problem name: Multiply Strings (Medium)

Problem statement: Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly. 

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

*/

//Sulution
class Solution 
{
    public String multiply(String num1, String num2) 
    {
        if (num1.equals("0") || num2.equals("0")) 
        {
            return "0";
        }
        int m = num1.length() - 1, n = num2.length() - 1, carry = 0;
        String product = "";
        for (int i = 0; i <= m + n || carry != 0; ++i) 
        {
            for (int j = Math.max(0, i - n); j <= Math.min(i, m); ++j) 
            {
                carry += (num1.charAt(m - j) - '0') * (num2.charAt(n - i + j) - '0');
            }
            product += (char)(carry % 10 + '0');
            carry /= 10;
        }
        return new StringBuilder(product).reverse().toString();
    }
}