#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n,q,a,x,index,i;
    cin>>n>>q;
    ll int v[n];
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v,v+n);    
    while(q--)
    {
        cin>>x;
        a=lower_bound(v,v+n,x)-v;
        index = n-a;
        if(v[a]==x)
        cout<<"0";
        else if(index%2==0  || x>v[n-1])
        cout<<"POSITIVE";
        else
        cout<<"NEGATIVE";
        cout<<"\n";
    }
    return 0;
}

// Sample input/output 

// Example Input
// 4 6
// 1 3 5 100
// -2
// 2
// 4
// 80
// 107
// 5

// Example Output
// POSITIVE
// NEGATIVE
// POSITIVE
// NEGATIVE
// POSITIVE
// 0