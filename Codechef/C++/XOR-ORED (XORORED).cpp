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
    int bits[32]={0};
    for(int i=0;i<n;i++)
    {
        indx=0;
        ans=a[i];
        while(ans)
        {
            bits[indx] += ans & 1;
            ans >>=1;
            indx++;
        }
    }
    ans=0;
    for(int i=0;i<32;i++)
    {
        if(bits[i]>(n/2))
        ans = ans + (1<<i);
    }
    for(int i=0;i<n;i++)
    mx = (a[i]^ans) | mx;
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