#include <iostream>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) 
	{
        string hack;
        if(palindrome.length()==1) 
		   return hack;
        for(int i=0;i<palindrome.length()/2;i++)
		{
            if(palindrome[i]!='a')
			{
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[palindrome.length()-1]='b';
        return palindrome;
    }
};
