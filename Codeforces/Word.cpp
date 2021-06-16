#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll upper=0,lower=0;
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
            upper++;
        else if(islower(s[i]))
            lower++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(lower==upper || lower>upper)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                s[i]=(s[i]+32);
            }
            
        }
        else
        {
            if(s[i]>=97 && s[i]<=122)
            {
                s[i]=(s[i]-32);
            }
        }
        
        
    }
    cout<<s<<endl;
    
    
    
    return 0;
}