#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t--)
    {
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='G' && s[i+1]=='G')
                continue;
            else if(s[i]=='G' && s[i+1]=='B')
                continue;
            else if(s[i]=='B' && s[i+1]=='G')
                {
                    s[i]='G';
                    s[i+1]='B';
                    i=i+1;
                }
        }
    
        
    }
    
    cout<<s<<endl;
        
        
        
    return 0;
}