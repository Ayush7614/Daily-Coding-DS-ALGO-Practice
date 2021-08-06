// Problem link: https://www.codechef.com/JULY21C/problems/XXOORR
// Explanation: We have to count the number of ones in the binary representaion of the given number and maintain a vector to find out the occurance of a each bit.
// For example 4 contains a single 1 bit at the index 3 while 5 contains 2 bits at index 3 and 1 therefore the vector will be upadated as 2 for index 3 and 1 for index 1
// Iterate through the vector and find out if the number of operations required by following contions:
// If the number of occurance at a particular index is divisible by k then increase the counter by k 
// If the number of occurance at a particular index is not divisible by k then increase the counter by k+1 since the remaning operations will be completed in the next cycle(hence 1)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int n,k;
    cin>>n>>k;
    ll int a[n];
    for(ll int i=0;i<n;i++)
    cin>>a[i];
    vector<ll int> index(32,0);
    ll int temp,j;
    for(ll int i=0;i<n;i++)
    {                               // Counting the number of bits in the given array at a given index
        j=0; 
        while(a[i]>0)
        {
            index[j]+=a[i]%2;
            a[i]>>=1;
            j++;    
        }
    }
    ll int ans=0;
    for(int i=0;i<index.size();i++)
    {
        if(index[i]%k==0)           // Iterate through the vector storing the occurance of index if divisible by k then increase it by k else k+1
        ans = ans + index[i]/k;
        else
        ans = ans + index[i]/k + 1;
    }  
    cout<<ans<<"\n";
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
// 1
// 3 2
// 3 6 10

// Sample Output
// 5