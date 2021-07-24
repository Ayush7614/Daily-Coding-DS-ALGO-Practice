/*  LINK TO THE QUESTION: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/*/
//GIVEN:Given the string S.
//AIM: return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

//EXAMPLE:
/*
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
*/
 //SOLUTION:

#include<iostream>
using namespace std;

    int findTheLongestSubstring(string s) {
      
        unordered_map<bitset<5>,int>mp;
        bitset<5>b;
        mp[b]=-1;
        // Pos map stores indices for flipping certain vowel bits
        map<char,int>pos;
        pos.insert({'a',0});
        pos.insert({'e',1});
        pos.insert({'i',2});
        pos.insert({'o',3});
        pos.insert({'u',4});
        int ans=0;
        for(int i=0;i<s.size();i++)
        {   
            // Our character should be a vowel
            if(pos.find(s[i])!=pos.end())
                b.flip(pos[s[i]]);
            if(mp.find(b)!=mp.end())
            {
                ans=max(ans,i-mp[b]);
            }
            else{
                mp[b]=i;
            }
        }
        return ans;
        
    }
int main()
{
    string s;
    cin>>s;
    int ans=findTheLongestSubstring(s);
    cout<<ans;
    return 0;
}
    