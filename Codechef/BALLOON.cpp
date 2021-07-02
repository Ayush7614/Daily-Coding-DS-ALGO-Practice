#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int t;
    cin>>t;
    while(t--)
    {
        int n,a,max;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        max = 6;
        for(int i=7;i<n;i++)
        {
            if(v[i]<8)
            max=i;
        }
        cout<<" = "<<(max+1)<<endl;
    }
}

// Sample input/output:

// Example Input
// 3
// 7
// 1 2 3 4 5 7 6
// 8
// 8 7 6 5 4 3 2 1
// 9
// 7 4 3 5 6 1 8 2 9

// Example Output
// 7
// 8
// 8