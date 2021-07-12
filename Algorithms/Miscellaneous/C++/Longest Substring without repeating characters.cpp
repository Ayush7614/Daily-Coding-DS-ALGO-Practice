#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int i=0, j=0,ans=0;
      unordered_map<char,int>mp;
     while(j<s.length()){
      /*move the j and keep on tracking its occurence*/ 
       mp[s[j]]++;
       /* if map's size is == window size that means all charectoors are unique */
       
        if(mp.size()==j-i+1)
       {
         ans=max(ans,j-i+1);
         j++;
       }
     
       else
       {
         while(mp.size()<j-i+1)
         {
            mp[s[i]]--;
            if(mp[s[i]]==0){
             mp.erase(s[i]);
            }
             i++;
            
         }
         j++;
       }
     }
       return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	  string s;
    cin>>s;

    Solution obj;
    int ans=obj.lengthOfLongestSubstring(s);
    cout<<ans<<endl;
    return 0;
}
