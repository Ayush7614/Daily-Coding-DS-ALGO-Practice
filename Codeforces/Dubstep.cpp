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
    if(s.length()>=3)
    {
    for(int i=0;i<s.length()-2;i++)
    {
        if(s.substr(i,3)=="WUB")
        {
            s.erase(i,3);
            s.insert(i,1,' ');
        }
    }
    
    int i=0;
    while(s[i]==' ')
        s.erase(i,1);
        
    i=s.length()-1;
    while(s[i]==' ')
    {
        s.erase(i,1);
        i=s.length()-1;
    }
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==' ' && s[i+1]==' ')
        {
            s.erase(i,1);
        }
    }
    }
    cout<<s<<endl;    
    
    
    return 0;
}