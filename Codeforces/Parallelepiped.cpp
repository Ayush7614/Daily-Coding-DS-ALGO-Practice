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
    ll s1,s2,s3;
    cin>>s1>>s2>>s3;
    ll a = sqrt((s1*s3)/s2);
    ll b = sqrt((s1*s2)/s3);
    ll c = sqrt((s2*s3)/s1);
    cout<<(4*(a+b+c))<<endl;
    
    
    
    return 0;
}