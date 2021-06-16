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
    string s;
    cin>>s;
    ll countZero=0,countOne=0;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            countZero++;
            if(countZero>=7)
                break;
            countOne=0;    
        }
        else if(s[i]=='1')
        {
            countOne++;
            if(countOne>=7)
                break;
            countZero=0;    
        }
        
    }
    
    if(countZero>=7 || countOne>=7)
    
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    
    
    return 0;
}s