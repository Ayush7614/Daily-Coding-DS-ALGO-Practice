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
    if(s[0]>=97 && s[0]<=122)
        s[0]=s[0]-32;
    cout<<s<<endl;    
    
    
    
    return 0;
}