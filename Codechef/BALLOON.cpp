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