#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(3*n+i);
    }
    for(auto it: v)
        cout<<it<<" ";
    cout<<endl;    
    
    
    
    return 0;
}