/*
Problem: Letter Combinations of a Phone Number on LeetCode
Solution by AtrikGit6174 using recursion.

Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. Return the answer in any order.

The digits are mapped just like a keypad of a mobile phone. 
[Please check the Solution class' constructor to understand].

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:

-- 0 <= digits.length <= 4
-- digits[i] is a digit in the range ['2', '9'].

Idea to solve: This approach is more like a recursive Cartesian product.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
    static map <char, vector<string>> dicty;
    static int counter;
    //Ideally a better option to make this a static object
public:
    Solution ()
    {
        counter++;
        
        if (counter==1)
        {
            dicty['2']= {"a", "b", "c"};
            dicty['3']= {"d", "e", "f"};
            dicty['4']= {"g", "h", "i"};
            dicty['5']= {"j", "k", "l"};
            dicty['6']= {"m", "n", "o"};
            dicty['7']= {"p", "q", "r", "s"};
            dicty['8']= {"t", "u", "v"};
            dicty['9']= {"w", "x", "y", "z"};
        }
    }
    
    vector<string> letterCombinations(string digits, int beg= 0) 
    {
        if (digits.size()==beg)
            return {};
        
        return (cross (dicty[digits[beg]], letterCombinations (digits, beg+1)));            
        
    }
    
    vector<string> cross (vector<string> vec1, vector<string> vec2)
    {
        if (vec2.size()==0)
            return vec1;
        
        vector<string> vec3;
        
        for (int i=0, j=0; i<vec1.size();)
        {
            vec3.push_back (vec1[i] + vec2[j++]);
            
            if (j==vec2.size())
            {
                i++;
                j=0;
            }
        }
        
        return vec3;
    }
};

int Solution::counter= 0;
map <char, vector<string>> Solution::dicty;

int main() 
{
	// your code goes here
	
	cout<<"Enter the number of test cases: ";
	int t; cin>>t;
	
	for (int count= 1; count<=t; count++)
	{
	    cout<<"TEST CASE "<<count<<"\nEnter the string of digits (length [0,4]): ";
	    string digits; std::getline(cin, digits);
	    
	    Solution ob;
	    
	    cout<<"[ ";
	    for (string s : ob.letterCombinations(digits))
	    {
	        cout<<"\""<<s<<"\" ";
	    }
	    
	    cout<<"]\n\n";
	}
	
	return 0;
}
