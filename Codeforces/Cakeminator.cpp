#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
     ll a,b;
     cin>>a>>b;
     string s[20];
     loop(i,0,a)
     cin>>s[i];
     int res =0;
     loop(i,0,a)
     loop(j,0,b) {
     int ok1=1,ok2=1;
     loop(k,0,a) if(s[k][j] == 'S') ok1 = 0;
     loop(k,0,b) if(s[i][k] == 'S') ok2 = 0;
    
     if(ok1 + ok2 > 0) res++;
  }
     cout<<res<<endl;
    
    
    
    return 0;
}