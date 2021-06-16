#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b)  for(int i=a;i<=(b);i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    string ans="";
    cin>>a>>b;
    loop(i,0,a.length()-1)
    {
        cout<<(((int)a[i]) ^ ((int)b[i]));
    }
    
    
    return 0;
}