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
    ll n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    
    ll totalDrink = k*l;
    ll totalSlices = c*d;
    ll requiredSalt = p/np;
    ll requiredDrink = totalDrink/nl;
    ll ans;
  ans = min(requiredDrink,min(requiredSalt,totalSlices));
    cout<<ans/n<<endl;
    
    
    
    return 0;
}