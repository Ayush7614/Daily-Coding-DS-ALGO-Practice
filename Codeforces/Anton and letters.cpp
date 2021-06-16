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
    
    string str;
    getline(cin,str);
    unordered_set<char> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>=97 && str[i]<=122)
            s.insert(str[i]);
    }
    cout<<s.size()<<endl;
    
    
    
    return 0;
}