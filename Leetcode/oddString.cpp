/*link of this question : https://leetcode.com/problems/largest-odd-number-in-string/


  You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
  A substring is a contiguous sequence of characters within a string.

   Input: num = "52"
   Output: "5"
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 string largestOddNumber(string num){
   int l=num.length()-1;

    while(l>=0)
    {
      if((num[l]-'0')%2)
        break;

      l--;
    }
    if(l<0)
        return "";
    return num.substr(0,l+1);
}
int main()
 {
     string s;
     cin>>s;
      cout<<largestOddNumber(s);
 }
