// Intro:
// Problem link: https://www.codechef.com/JULY21C/problems/RELATIVE
// Explanation:
// We have to find the height from the formula v^2 = 2*g*h
// Here we have to find the height and it given that the velocity is that of speed of light therefore the formula can be further modified as c^2/2*g = h 
// The speed of light c and acceleration due to gravity is taken as input, so we have to apply the above formula and output thee height in meters

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int g,c;
    cin>>g>>c;
    cout<<(c*c)/(2*g)<<"\n";
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

// Sample Input
// 3
// 7 1400
// 5 1000
// 10 1000

// Sample Output
// 140000
// 100000
// 50000