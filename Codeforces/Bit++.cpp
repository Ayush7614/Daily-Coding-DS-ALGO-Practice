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
    int x=0;
    while(n--)
    {
        string s;
        cin>>s;
        if(s=="++X" || s=="X++")
            x+=1;
        else if(s=="--X" || s=="X--")
            x-=1;
        
        
    }
    cout<<x<<endl;
    
    
    
    return 0;
}