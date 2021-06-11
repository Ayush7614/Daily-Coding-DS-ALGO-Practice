// Isomorphic Strings 

/* Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
   Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for 
   every character of str1 to every character of str2 while preserving the order.
   Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’  */


// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if(str1.length() != str2.length()){
            return false;
        }
        int a[26] = {0}, b[26] = {0};
        for(int i=0; i<str1.length(); i++){
            a[str1[i]-'a']++;
            b[str2[i]-'a']++;
            if(a[str1[i]-'a'] != b[str2[i]-'a']){
                return false;
            }
        }
        return true;
        
    }
};

int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  


/*  Input:   str1 = "aab", str2 = "xxy"
    Output:  True   */
