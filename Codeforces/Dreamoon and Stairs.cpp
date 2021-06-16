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
    int n,m;
    cin>>n>>m;
    int moves=n/2+(n%2);
    while(moves%m!=0)
        moves++;
    if(moves>n)
        moves=-1;
    cout<<moves<<endl;
    
    
    
    return 0;
}