#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,m,k;
	    cin>>n>>m>>k;
	    ll A[n+1][m+1];
	    memset(A,0,sizeof(A));
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	          cin>>A[i][j];
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	          A[i][j]+=A[i][j-1];
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	         A[i][j]+=A[i-1][j];
	    }
	    ll ans=0;
	    for(ll side=1;side<=n;side++)
	    {
	        for(ll i=1;i<=n-side+1;i++)
	        {
	            ll low=1;
	            ll high=m-side+1;
	            ll mid,p,flag=0;
	            while(low<=high)
	            {
	                mid=(high+low)/2;
	                ll sum=A[i+side-1][mid+side-1] - A[i+side-1][mid-1] - A[i-1][mid+side-1] + A[i-1][mid-1];
	                
	                if(sum>=k*side*side)
	                {
	                    high=mid-1;
	                    p=mid;
	                    flag=1;
	                }
	                else
	                    low=mid+1;
	                     
	                }
	                if(flag==1)
	                ans+=(m-side-p+2);
	            }
	        }
	        cout<<ans<<endl;
	    }
	
	return 0;
}
