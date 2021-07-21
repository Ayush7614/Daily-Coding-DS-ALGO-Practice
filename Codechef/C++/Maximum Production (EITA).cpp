// Intro:
// Problem link: https://www.codechef.com/JULY21C/problems/EITA
// We have to find the max work that can be done
// In first case we the total work done will be x*7
// In second case the total work done will be (y*d)+(7-d)*z, y*d represents the work done in first d days and (7-d)*z represents the work done in remaining time
// Find out the max from both of them 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int d,x,y,z;
    cin>>d>>x>>y>>z;
    cout<<max(x*7,(y*d)+(7-d)*z)<<"\n";
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

// Sample test cases:

// Sample Input
// 3
// 1 2 3 1
// 6 2 3 1
// 1 2 8 1

// Sample Output
// 14
// 19
// 14