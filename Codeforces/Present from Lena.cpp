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
    int index=2*n;
    for(int i=1;i<=(2*n)+1;i++)
    {
        if(i<=n+1)
        {
            int count =0;
            for(int j=1;j<=(2*n)+1;j++)
            {
                if(j<n+2-i)
                    cout<<"  ";
                else if(j==n+2-i)
                    cout<<0;
                else if(j>n+2-i && j<=n+1)
                {
                    count++;
                    cout<<" "<<count;
                }
                else if(j>n+1 && j<=n+i)
                {
                    count--;
                    cout<<" "<<count;
                }
            }
        }
        else
        {
            int count =0;
            for(int j=1;j<=(2*n)+1;j++)
            {
                if(j<i-n)
                    cout<<"  ";
                else if(j==i-n)
                    cout<<0;
                else if(j>i-n && j<=n+1)
                {
                    count++;
                    cout<<" "<<count;
                }
                else if(j>n+1 && j<=index)
                {
                    count--;
                    cout<<" "<<count;
                }
            }
             index--;
        }
        cout<<endl;
    }
    
    
    
    return 0;
}