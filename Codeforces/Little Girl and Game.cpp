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
    unordered_map<char,ll> mp;
    loop(i,0,s.length())
        mp[s[i]]++;
    ll countOdd=0;
    for(auto it:mp)
    {
        if(it.second%2!=0)
            countOdd++;
    }
    if(countOdd<=1)
        cout<<"First"<<endl;
    else
    {
        if(countOdd%2==0)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
    }
    
    return 0;
}