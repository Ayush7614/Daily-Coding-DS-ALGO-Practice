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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        char arr[n][n];
        vector<int> v;
        loop(i,0,n)
        {
            loop(j,0,n)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='*')
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        if(v[0]==v[2])
        {
            arr[(v[0]+1)%n][v[1]]='*';
            arr[(v[0]+1)%n][v[3]]='*';
        }
        else if(v[1]==v[3])
        {
            arr[v[0]][(v[1]+1)%n]='*';
            arr[v[2]][(v[3]+1)%n]='*';
            
        }
        else
        {
            arr[v[0]][v[3]]='*';
            arr[v[2]][v[1]]='*';
        }
        loop(i,0,n)
        {
            loop(j,0,n)
            cout<<arr[i][j];
            cout<<endl;
        }
        
        
    }
    
    
    
    return 0;
}