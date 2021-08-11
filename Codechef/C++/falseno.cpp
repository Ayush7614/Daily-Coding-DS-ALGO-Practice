#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        char ch;
        string st1="10";
        ch = s.at(0);
        if(ch == '1')
        s.replace(0,1,st1);
        else
        s="1"+s;
        cout<<s<<endl;    
    }
    return 0;
}