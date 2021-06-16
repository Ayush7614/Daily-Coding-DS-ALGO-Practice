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
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
            s[i] = s[i]+32;
            
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
        {
            s.erase(s.begin()+i);
            i=i-1;
        }
    }
    loop(i,0,s.length())
    {
        cout<<'.'<<s[i];
    }
    cout<<endl;
    
    
    return 0;
}