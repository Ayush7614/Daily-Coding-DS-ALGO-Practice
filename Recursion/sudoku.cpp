#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mat[9][9];

bool check(ll i,ll j,ll k)
{
    for(ll g=0;g<9;g++)
    {
        if(mat[g][j]==k || mat[i][g]==k)
            return false;
    }

    ll a,b;
    a=((i+3)/3)*3;
    b=((j+3)/3)*3;

    for(ll g=a-3;g<a;g++)
        for(ll x=b-3;x<b;x++)
        if(mat[g][x]==k)
        return false;

    return true;
}

bool rec(ll n,ll i,ll j)
{
    if(i==n)
     {
         cout<<endl;
          for(ll a=0;a<9;a++)
          {
            for(ll b=0;b<9;b++)
             cout<<mat[a][b]<<" ";
             cout<<endl;
          }
          return true;
     }

    if(j==n)
        return rec(n,i+1,0);

    if(mat[i][j]!=0)
        return rec(n,i,j+1);

    for(ll k=1;k<=9;k++)
        if(check(i,j,k))
        {
           mat[i][j]=k;
           bool b=rec(n,i,j+1);
           if(b==true)
            return true;
        }

    mat[i][j]=0;
    return false;
}

int main()
{
    ll i,j,n=9;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        cin>>mat[i][j];


    bool b=rec(n,0,0);
    if(b==0)
        cout<<"Matrix not exist"<<endl;
    return 0;
}
