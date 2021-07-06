/*
Problem:
"Add Binary" on LeetCode by AtrikGit6174
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

-- 1 <= a.length, b.length <= 104
-- a and b consist only of '0' or '1' characters.
-- Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <string>       
#include <algorithm>    //reverse()
using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        if (a=="0")
            return b;
        if (b=="0")
            return a;
        
        int carry= 0;
        
        //to avoid separate cases
        string &big= (a.size()>=b.size()) ? a:b;
        string &small= (a.size()<b.size()) ? a:b;
        
        //reverse iterators
        auto itbig= big.rbegin();                       
        auto itsmall= small.rbegin();
        
        int temp;
        
        while (itsmall!=small.rend())
        {
            //exploting the fact that char is promoted to int
            temp= (*itbig - '0') + (*itsmall - '0') + carry ;
            
            if (temp>1)
                carry= 1;
            else
                carry= 0;
            
            switch (temp)
            {
                case 0:                    
                case 2:
                    *itbig= '0';
                    break;
                    
                case 1:
                case 3:
                    *itbig= '1';
                    break;
            }
            
            itsmall++;
            itbig++;
        }
        
        if (carry)
        {
            while (itbig!=big.rend())
            {
                temp= carry + (*itbig - '0');
                
                if (temp>1)
                    carry= 1;
                else
                    carry= 0;
                
                switch (temp)
                {
                    case 0:
                    case 2:
                        *itbig= '0';
                        break;
                    case 1:
                        *itbig= '1';
                        break;
                }
                
                itbig++;
            }
            
            //overflow
            if (carry and itbig==big.rend())
            {
                reverse(big.begin(), big.end());
                big.push_back('1');
                reverse(big.begin(), big.end());
            }
        }
        
        return big;
    }
};

int main ()
{
    cout<<"Enter first binary string: ";
    string a; cin>>a;

    cout<<"\nEnter second binary string: ";
    string b; cin>>b;

    Solution *ob;
    cout<<"\nSum= "<<ob->addBinary(a,b);

    return 0;
}