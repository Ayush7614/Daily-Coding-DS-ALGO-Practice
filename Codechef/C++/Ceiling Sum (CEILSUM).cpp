// Problem link: https://www.codechef.com/START7C/problems/CEILSUM
// If  A==B then the only value of X possible wiil be A(or B) therefore the value of Ceil((B-B)/2)+Ceil((A-A)/2) = 0
// Further there are 4 more conditions 
// ceil(B-X)      ceil(X-A)     Max
//    Even          Even        B-A/2 (since both are even therefore ceil dosen't matter)
//    Even          Odd         (B-X + X-A + 1)/2 = (B-A+1)/2 
//    Odd           Even        (B-X+1 + X-A)/2 = (B-A+1)/2
//    Odd           Odd         (B-X+1 + X-A + 1)/2 = (B-A+2)/2
// Therefore is both of them are even/odd the condition to find max value is (B-A+2)/2 (sinve we have to maximize)
// If both different then the maximum will be  (B-A+1)/2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int a,b;
    cin>>a>>b;
    if(a==b)
    cout<<"0";
    else
    {
        if((b-a)%2 == 0)
        cout<<(b-a+2)/2;
        else
        cout<<(b-a+1)/2;
    }
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
// 3
// 2 2
// 1 11
// 13 6

// Sample Output 1 
// 0
// 6
// -3