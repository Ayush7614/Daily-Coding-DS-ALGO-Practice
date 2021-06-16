#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll year;
    unordered_set<char> s;
    cin>>year;
    year+=1;
    ll ans=year;
    while(year>0)
    {
        int x=year%10;
        s.insert(x);
        year=year/10;
    }
    
    while(s.size()<4)
    {
        if(s.size()==4)
        break;
        else
        {
            s.clear();
            ans+=1;
            ll temp=ans;
            while(temp>0)
            {
                int rem=temp%10;
                s.insert(rem);
                temp=temp/10;
                
            }
            
        }
        
        
        
    }
    
    cout<<ans; 
    

    
    return 0;
}