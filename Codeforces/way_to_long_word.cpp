#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
   string s;
   string sn;
   cin>>s;
   if(s.length()>10){
      int count=s.length()-2;
      cout<<s[0]<<count<<s[s.length()-1]<<endl;
   }
   else{
       cout<<s<<endl;
   }
    }
    return 0;
    
}