//Problem:
//Professor Dumbledore is helping Harry destroy the Horcruxes. 
//He went to Gaunt Shack as he suspected a Horcrux to be present there. 
//He saw Marvolo Gaunt's Ring and identified it as a Horcrux. 
//Although he destroyed it, he is still affected by its curse. 
//Professor Snape is helping Dumbledore remove the curse. 
//For this, he wants to give Dumbledore exactly x drops of the potion he made.

//Value of x is calculated as maximum of p·ai + q·aj + r·ak for given p, q, r and array a1, a2, ... an such that 1 ≤ i ≤ j ≤ k ≤ n. 
//Help Snape find the value of x. Do note that the value of x may be negative.

//Input
//First line of input contains 4 integers n, p, q, r ( - 109 ≤ p, q, r ≤ 109, 1 ≤ n ≤ 105).

//Next line of input contains n space separated integers a1, a2, ... an ( - 109 ≤ ai ≤ 109).

//Output
//Output a single integer the maximum value of p·ai + q·aj + r·ak that can be obtained provided 1 ≤ i ≤ j ≤ k ≤ n.
//Examples:
//input-
//5 1 2 3
//1 2 3 4 5
//output-
//30
//input-
//5 1 2 -3
//-1 -2 -3 -4 -5
//output-
//12
//solution (using dynamic programming)

#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn],b[4],dp[maxn][4];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=3;i++)
          cin>>b[i];
        for(int i=1;i<=n;i++)
          cin>>a[i];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=3;j++)
              dp[i][j]=-INF;
        }
        for(int i=1;i<=n;i++)
          for(int j=1;j<=3;j++)
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]+(ll)(a[i]*b[j])));
        cout<<dp[n][3]<<endl;
    }
    return 0;
}
