#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
            count++;
        
    }
    cout<<count<<endl;
    
    
    
    return 0;
}