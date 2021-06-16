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
    ll k;
    cin>>k;
    string s;
    cin>>s;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        bool flag=false;
        for(auto i : m)
        {
            if(i.second%k!=0)
            {
                cout<<-1<<endl;
                flag=true;
                break;
            }
        }
        
        string ans="";
        for(auto it: m)
        {
            for(int i=0;i<(it.second/k);i++)
            {
                ans +=(it.first);
            }
        }
        if(flag==false)
        {
            for(int i=0;i<k;i++)
            {
                 cout<<ans;
            }
            cout<<endl;
        }
    
    
    
    
    return 0;
}