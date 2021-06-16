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
    ll t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;

    int i;
    for(i=0;i<t;i++)
    { 
      if(s[i]=='S' && sy>ey)
      {
        sy=sy-1;
      }
      if(s[i]=='E' && sx<ex)
      {
        sx=sx+1;      
      }
      if(s[i]=='W' && sx>ex)
      {
        sx = sx-1;            
      } 
      if(s[i]=='N' && sy<ey)
      {
        sy= sy +1;
      }
      if(sx==ex && sy==ey)
      {
        break;
      }
    }
    if(sx==ex && sy==ey)
        cout<<i+1<<endl;
    else
        cout<<-1<<endl;
    
    
    
    return 0;
}