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
    string s;
    loop(i,0,n)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='.')
            {
                if((i+j)%2!=0)
                    s[j]='W';
                else
                    s[j]='B';
            }
        }
        cout<<s<<endl;
    }
    
    
    
    return 0;
}