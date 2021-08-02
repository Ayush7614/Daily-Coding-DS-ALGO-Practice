// Problem link: https://www.codechef.com/problems/XORORED
// We have to find the binary representation of each number and maintain a array which keeps track of all the 1's and 0's at a specific location
// Eg: 7 is represented as 111 and 5 as 101 therfore the array will store the frequency of 1's at a location as 2 1 2
// in order to find the X we have to check if the frequency of 1 at a index is greater than n/2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,mx=0,indx=0,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int bits[32]={0};               // array to store the frequency of 1's
    for(int i=0;i<n;i++)
    {
        indx=0;
        ans=a[i];
        while(ans)                      
        {
            bits[indx] += ans & 1;
            ans >>=1;                   // shift the number by 1
            indx++;
        }
    }
    ans=0;
    for(int i=0;i<32;i++)
    {
        if(bits[i]>(n/2))               // Constructing X
        ans = ans + (1<<i);     
    }
    for(int i=0;i<n;i++)
    mx = (a[i]^ans) | mx;               // Find out  (A1⊕X)∨⋯∨(AN⊕X)
    cout<<ans<<" "<<mx<<"\n";
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
// 1
// 2
// 4 6

// Sample Output 1 
// 6 2