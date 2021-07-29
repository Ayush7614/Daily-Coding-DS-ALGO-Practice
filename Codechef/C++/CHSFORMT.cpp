// Problem link: https://www.codechef.com/START7C/problems/CHSFORMT
// This is a simple if else problem
// Output   Condition
//  1        if (a+b)<3
//  2        else if 3≤(a+b)≤10
//  3        else if 11≤(a+b)≤60
//  4        else 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a,b,s;
    cin>>a>>b;
    s=a+b;
    if(s<3)
    cout<<"1";
    else if (s>=3 && s<=10)
    cout<<"2";
    else if(s>=11 && s<=60)
    cout<<"3";
    else
    cout<<"4";
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

// Sample input/output

// Sample Input 1 
// 4
// 1 0
// 4 1
// 100 0
// 20 5

// Sample Output 1 
// 1
// 2
// 4
// 3