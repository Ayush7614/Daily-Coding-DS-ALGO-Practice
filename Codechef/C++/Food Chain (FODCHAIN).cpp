// Problem link: https://www.codechef.com/START7C/problems/FODCHAIN
// In this problem we have to divide e/k repeatedly until e becomes zero 
// Maintain a counter to find out when e becomes zero

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int e,k,a=0; // here a is counter 
    cin>>e>>k;
    while(e>0)
    {
        e=e/k;
        a++;
    }
    cout<<a<<"\n";
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
// 3
// 5 3
// 6 7
// 10 2

// Sample Output 1 
// 2
// 1
// 4