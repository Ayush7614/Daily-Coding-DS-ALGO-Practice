// Problem link: https://www.codechef.com/START6C/problems/CRICRANK
// We have to maintain a counter and increase it if r1>r2,w1>w2 or c1>c2 condition arises
// We have to output A if player A is better than B, A is better than B if more than 1 of the above conditions are satisfied, i.e count>1
// If count value is <=1 it implies that B is better therefore output B

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a[3],b[3],cnt=0;
    for(int i=0;i<3;i++)        // array is used to take inputs instead of r1,w1,c1 to make comparison easy 
    cin>>a[i];
    for(int i=0;i<3;i++)        // array is used to take inputs instead of r2,w2,c2
    cin>>b[i];
    for(int i=0;i<3;i++)
    {
        if(a[i]>b[i])
        cnt++;
    }
    if(cnt>1)
    cout<<"A\n";
    else
    cout<<"B\n";
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
// 0 1 2
// 2 3 4
// 10 10 10
// 8 8 8
// 10 0 10
// 0 10 0

// Sample Output 1 
// B
// A
// A