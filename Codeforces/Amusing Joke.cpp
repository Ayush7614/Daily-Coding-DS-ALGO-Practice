#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>

string found;
bool check(char x)
{
    bool flag=false;
    for(int i=0;i<found.length();i++)
    {
        if(found[i]==x)
        {
            found.erase(found.begin()+i);
            flag=true;
            break;
            
        }
        
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string guest,host;
    cin>>guest>>host>>found;
    ll n = guest.length();
    ll m = host.length();
    ll x = found.length();
    if(n+m<x)
        cout<<"NO"<<endl;
    else
    {
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(check(guest[i])==true)
            continue;
            else
            {
                flag=true;
                break;
            }
            
        }
        
        if(flag==true)
            cout<<"NO"<<endl;
        else
        {
            bool flag2=false;
            for(int i=0;i<m;i++)
            {
                if(check(host[i])==true)
                continue;
                else
                {
                    flag2=true;
                    break;
                }
            }
            if(flag2==true)
                cout<<"NO"<<endl;
            else
            {
                if(found.length()==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
    }
    
    
    return 0;
}