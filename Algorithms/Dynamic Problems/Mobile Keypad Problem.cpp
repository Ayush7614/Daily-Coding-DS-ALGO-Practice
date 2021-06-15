#include <bits/stdc++.h>
using namespace std;

int m[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
long long dp[10][1005];

long long count(int i,int j, int n)
{
    if(n==1) return 1;
    if(dp[m[i][j]][n]!=-1) return dp[m[i][j]][n];
    long long a=0,b=0,c=0,d=0,e=0;
    a = count(i,j,n-1);
    if(j-1>=0 && m[i][j-1]!=-1) b = count(i,j-1,n-1);   // left
    if(j+1<3 && m[i][j+1]!=-1) c = count(i,j+1,n-1);    // right
    if(i-1>=0 && m[i-1][j]!=-1) d = count(i-1,j,n-1);   // up
    if(i+1<4 && m[i+1][j]!=-1) e = count(i+1,j,n-1);    // down

    dp[m[i][j]][n] = a+b+c+d+e;
    return dp[m[i][j]][n];
}

long long getCount(int n)
{
  dp[10][n+1];
  long long r=0;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
          if(m[i][j]!=-1)
              r+=count(i,j,n);
      }
  }
  return r;
}

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
	      cout << getCount(n) << "\n";
	     
    }
    return 0;
}
