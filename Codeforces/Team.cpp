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
    int count =0;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((a==1&&b==1) || (a==1 && c==1) || (b==1 && c==1))
            count++;
        
        
    }
    cout<<count<<endl;
    
    
    
    return 0;
}