#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    if(s.length()==1)
        cout<<s<<endl;
    else
    {
        vector<int> v;
        string ans="";
        for(int i=0;i<s.length();i+=2)
        {
            v.push_back(((int)s[i]));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            ans+=(char)v[i];
            ans+='+';
        }
        ans+=(char)v[v.size()-1];
        cout<<ans<<endl;
        
    }
    
    
    
    return 0;
}