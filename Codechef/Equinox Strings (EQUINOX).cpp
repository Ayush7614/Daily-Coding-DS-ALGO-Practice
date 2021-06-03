#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<=(b);i++)
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
        ll n,a,b;
        cin>>n>>a>>b;
        ll sarthak=0,anuradha=0;
        while(n--)
        {
            string s;
            cin>>s;
            if(s[0]=='E' || s[0]=='Q' || s[0]=='U' || s[0]=='I' || s[0]=='N' || s[0]=='O' || s[0]=='X')
                sarthak += a;
            else
                anuradha += b;
            
            
            
        }
        
        if(sarthak > anuradha )
            cout<<"SARTHAK"<<endl;
        else if(sarthak < anuradha )
            cout<<"ANURADHA"<<endl;
        else
            cout<<"DRAW"<<endl;
        
    }
    
    
    
    return 0;
}