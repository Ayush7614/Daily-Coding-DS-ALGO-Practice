/*Link to problem:
https://leetcode.com/problems/palindromic-substrings/
*/

/*Algorithm : For finding palindromic substring we can start from middle and can go left and right simultaneously.
In this method if we will take odd length substring we will start our left and right pointer from same middle element and for even
if left is middle then right will be middle+1. So we will iterate over each i and will count odd and even length palindromic-substrings
and add them to get answer.


*/


#include<bits/stdc++.h>

using namespace std;


int countSubstrings(string s) {
        
    int n=s.length(),len=0,l,r,i;
        
    if(n==1)
        return 1;
    
    for(i=0;i<n;i++) // For odd length palindromic substrings
    {
        l=i; // left pointer
        r=i; //right pointer
                
        while(l>=0 && r<n && s[l]==s[r]) //if palindrome
        {
            len++;
            l--;
            r++;
                    
        }
    }
            
     
    for(i=0;i<n;i++) // For even length palindromic substrings
    {
        l=i; // left pointer
        r=i+1; //right pointer

        while(l>=0 && r<n && s[l]==s[r]) //if palindrome
        {
            len++;
            l--;
            r++;
                    
        }
    }
            
   
    return len;
        
}

int main()
{
    string s;
    cin>>s;

    int ans=countSubstrings(s);

    cout<<"Number of palindromic substrings= "<<ans;

    return 0;
}

/*
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa"


*/