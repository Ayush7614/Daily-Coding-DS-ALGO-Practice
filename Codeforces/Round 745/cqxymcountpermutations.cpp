#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
      cin>>t;
      while(t--)
      {
          int n;
          cin>>n;
      ll ans=1;
      ll mod=1e9+7;

      for(int i=2*n;i>=3;i--){
        ans=(ans*i)%mod;
      }
      ans=ans%mod;

      cout<<ans<<"\n";
      }
}
