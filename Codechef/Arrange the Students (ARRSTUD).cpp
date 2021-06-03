#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;
        ll counter=1;
        for(ll i=0;i<s1.length()-1;i++)
        {
            if(s1[i]=='1' && s1[i+1]=='1')
            counter++;
        }
        cout<<counter<<endl;
        
        
    }
    
    
    
    return 0;
}