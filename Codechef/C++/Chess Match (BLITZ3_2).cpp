// Intro:
// Problem link: https://www.codechef.com/problems/BLITZ3_2
// The total time remaining on each players clock after the game is concluded is given by a and b, therefore the total time remaining is (a+b)
// The total time provided to each player is (180 + N) seconds therefore total time provided is 2*(180 + N)
// The duration of the game = total time provided - Total time remaining

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;                                   
    cout<<(2*(180+n)-(a+b))<<"\n";                     // output (total time provided - Total time remaining)
}
int main()
{    
    ios_base::sync_with_stdio(false);                 // Fast I/O for Competitive Programming
    cin.tie(NULL);
    ll int t;
    cin>>t;                                          // Taking input for test cases
    while(t--)
    {
        solve();
    }
    return 0;
}

// Sample Input/Output 


// Example Input

// 3
// 10 0 2
// 11 2 1
// 12 192 192

// Example Output

// 378
// 379
// 0