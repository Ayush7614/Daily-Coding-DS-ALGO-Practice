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
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.length()<=10)
            cout<<s<<endl;
        else
        {
            ll num = (s.length())-2;
         cout<<s[0]<<num<<(s[s.length()-1])<<endl;
        }
        
        
    }
    
    
    
    return 0;
}