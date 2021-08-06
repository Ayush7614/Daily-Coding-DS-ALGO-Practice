// Problem link: https://www.codechef.com/LTIME98C/problems/CHFSPL
// In this problem we have to find the sum of largest two numbers
// Easiest way to do it is to take the input in a array, sort it and find the sum of last two numbers

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a[3];
    for(int i=0;i<3;i++)
    cin>>a[i];
    sort(a,a+3);
    cout<<a[1]+a[2]<<"\n";  

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
// 2
// 4 2 8
// 10 14 18

// Sample Output 1 
// 12
// 32