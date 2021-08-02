// Problem link: https://www.codechef.com/LTIME98C/problems/REDALERT
// this is a simple if else problem
// maintain a counter l to record the water level
// if it rains on a particular day increase it by the amount of rain on that day a[i]
// If it does not rain on a day decrease it by d, if l-d<0 then replace l = 0 
// If at any point l>h then break out of loop and output YES else NO

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,d,h,l=0,f=0;
    cin>>n>>d>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        l+=a[i];
        else
        {
            if((l-d) >0)
            l=l-d;
            else
            l=0;
        }
        if(l>h)
        {
            f++;            // Flag to check if the statement breaks out or not 
            break;
        }
    }
    if(f>0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
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

// Sample input/output 

// Sample Input 1 
// 4
// 4 2 6
// 1 3 0 2
// 2 1 100
// 1 100
// 4 2 3
// 1 2 0 2
// 3 7 10
// 5 3 9 

// Sample Output 1 
// NO
// YES
// NO
// YES