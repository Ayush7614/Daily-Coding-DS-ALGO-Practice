#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    string ans="";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='-' && s[i+1]=='.')
        {
            ans+='1';
            i+=1;
        }
        else if(s[i]=='-' && s[i+1]=='-')
        {
            ans+='2';
            i+=1;
        }
        else if(s[i]=='.')
            ans+='0';
    }
    cout<<ans<<endl;
        
        
        
    return 0;
}