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
    bool flag=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='1' && s[i]!='4')
        {
            flag=true;
            break;
        }
        if(s[0]!='1')
        {
            flag=true;
            break;
            
        }
        if(s.find("444")!=s.npos)
        {
            flag=true;
            break;
        }
        
            
    }
    if(flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    
    return 0;
}