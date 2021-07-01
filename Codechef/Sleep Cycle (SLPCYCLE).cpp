#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int h,l,c=0;
    string s;
    cin>>l>>h>>s;
    vector<int> zeros;
    zeros.push_back(0);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0')
        c++;
        else
        {
            if(c>0)
            zeros.push_back(c);
            c=0;
        }
    }
    if(c>0)
    zeros.push_back(c);
    for(int i=1;i<zeros.size();i++)
    {
        if(zeros[i]>=h)
        {
            h=0;
            break;
        }
        if(h>(2*(h-zeros[i])))
        h=2*(h-zeros[i]);
    }
    if(h==0)
    cout<<"YES";
    else
    cout<<"NO";
    cout<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

// Test cases:

// Example Input
// 4
// 3 1
// 111
// 3 1
// 101
// 7 5
// 0000100
// 6 5
// 000010

// Example Output
// NO
// YES
// YES
// NO