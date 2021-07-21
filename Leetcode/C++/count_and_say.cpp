/*Link to problem :
https://leetcode.com/problems/count-and-say/

*/

/*Algorithm:
We will implement count & say as if n is given so we will evaluate the count and say from 3 to n-1 for n, n=1 and n=2 are base cases.
we keep count of consecutive repeating digits and when its not repeating we will store its frequency+digit in string 
and keep doing the same for rest of digits of string.

*/

#include <bits/stdc++.h>
using namespace std;


string countAndSay(int n) {
        
        int i,c,j;
        if(n==1)
            return "1"; //Base case
        if(n==2)
            return "11"; //Base case
        string s="11";
        
        for(i=3;i<=n;i++)
        {
            string t="";
            s=s+'&';
            c=1;
            
            for(j=1;j<s.length();j++)
            {
                if(s[j]==s[j-1]) // same digit repeating
                {
                    c++; // increasing the count
                }
                else
                {
                    t=t+to_string(c)+s[j-1]; // storing count+digit in form of string
                    c=1;
                }
            }
            s=t;
            
            
        }
        return s;
        
    }

    int main()
    {
        int n;
        cin>>n;

        string ans=countAndSay(n);
        cout<<ans;

    return 0;
    }

/*

Input: n = 4

Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

*/