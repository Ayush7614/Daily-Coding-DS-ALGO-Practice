#include <bits/stdc++.h>
using namespace std;

void rec(int i,int j,int n,int m,string osf)
{
    if(i==n-1 and j==m-1)
    {
        cout<<osf<<endl;
        return;
    }
    if(i>=n || j>=m)
        return;

    rec(i,j+1,n,m,osf+'R');
    rec(i+1,j,n,m,osf+'D');
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;

       rec(0,0,n,m,"");
    }
    return 0;
}
