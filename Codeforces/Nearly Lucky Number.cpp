#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin>>n;
    ll counter=0;
    for(int i=0;i<n.length();i++)
    {
        if(n[i]=='4')
        counter++;
        else if(n[i]=='7')
        counter++;
        
        
        
    }
    if(counter==4 || counter==7)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
    
    
    
    
    return 0;
}