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
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i]<='Z')
            str1[i]+=32;
        
    }
    for(int i=0;i<str2.length();i++)
    {
        if(str2[i]<='Z')
            str2[i]+=32;
    }
    if(str1<str2)
        cout<<-1<<endl;
    else if(str1>str2)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    
    
    
    return 0;
}