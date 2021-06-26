#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int t;
    cin>>t;
    while(t--)
    {
        ll int n,m,ones=0;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
        cin>>s[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s[i].size();j++)
            if(s[i][j]=='1')
            ones++;
        }
        if(ones%2!=0)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
}

// Sample test cases:

// Example Input
// 2
// 1 2
// 01
// 3 3
// 000
// 111
// 010

// Example Output

// YES
// NO