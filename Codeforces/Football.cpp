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
    ll n;
    cin>>n;
    unordered_map<string,int> m;
    loop(i,0,n)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    
        ll count =0;
        string ans="";
        for(auto it: m)
        {
            if(it.second > count)
            {
                count =it.second;
                ans = it.first;
            }
        }
        
        cout<<ans<<endl;
    
        
    
       
    
    
    
    
    return 0;
}