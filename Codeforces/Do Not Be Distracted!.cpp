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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1 || n==2)
            cout<<"YES"<<endl;
        else
        {
            bool flag=false;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]==s[i+1])
                    continue;
                else if(s[i]!=s[i+1])
                {
                    char c = s[i];
                    size_t found = s.find(c,i+1);
                    if(found!=string::npos)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            if(flag==true)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
            
        }
        
        
    }
    
    
    
    return 0;
}