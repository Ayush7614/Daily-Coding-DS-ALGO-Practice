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
        bool flag=1;
        if(s.at(0) != '<' || s.at(1) != '/' || s.at(s.length()) != '>')
        {
            cout<<"Error"<<endl;
        }
        else
        {
            for (int i = 2; i < s.length()-1; i++)
            {
                ch=s.at(i);
                if(isalnum(ch)==0)
                flag = 1;
                else
                flag=0;
            }
            if(flag==1)
            cout<<"Success"<<endl;
            else
            cout<<"Error"<<endl;
        }
    }
    return 0;
}