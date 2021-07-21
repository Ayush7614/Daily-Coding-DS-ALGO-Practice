#include <string.h>
using namespace std;
#define ll long long

ll possibleWays(ll coins[],ll n,ll val){
    ll dp[n][val+1],i,j;
    memset(dp,0,sizeof(dp));
    for(i=0;i<=val;i+=coins[0])
        dp[0][i]=1;
    for(j=0;j<n;j++)
        dp[j][0]=1;
    for(i=1;i<n;i++)
        for(j=1;j<=val;j++)
            if(j<coins[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
    return dp[n-1][val];
    
}
int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n,val,i;
	    cin>>n;
	    ll coins[n];
	    for(i=0;i<n;i++)
	        cin>>coins[i];
	    cin>>val;
	    cout<<possibleWays(coins,n,val)<<endl;
	}
	return 0;
}
