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
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    if(s==t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    
    
    return 0;
}