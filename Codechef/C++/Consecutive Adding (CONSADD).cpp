#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll a[1000][1000];
ll b[1000][1000];

bool ans(ll a[1000][1000],ll b[1000][1000],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=b[i][j])
            return false;
        }
    }
    return true;
}



int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c,x;
	    cin>>r>>c>>x;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>b[i][j];
	        }
	    }
	    
	    if(r<x  && c<x)
	    {
	        if(ans(a,b,r,c)==true)
	            cout<<"YES"<<endl;
	        else
	            cout<<"NO"<<endl;
	    }
	    else if(r<x)
	    {
	        for(int i=0;i<r;i++)
	        {
	            for(int j=0;j<(c-x+1);j++)
	            {
	                if(a[i][j]==b[i][j])
	                    continue;
	                else
	                {
	                    ll difference=b[i][j] - a[i][j];
	                    a[i][j]+=difference;
	                    ll k=1;
	                    while(k<x)
	                    {
	                        a[i][j+k]+=difference;
	                        k++;
	                    }
	                }
	                
	            }
	        }
	        
	        if(ans(a,b,r,c)==true)
	            cout<<"YES"<<endl;
	        else
	            cout<<"NO"<<endl;
	    }
	    
	    
	    else if(c<x)
	    {
	        for(int i=0;i<c;i++)
	        {
	            for(int j=0;j<(r-x+1);j++)
	            {
	                if(a[j][i]==b[j][i])
	                    continue;
	                else
	                {
	                    ll difference=b[j][i] - a[j][i];
	                    a[j][i] +=difference;
	                    ll k=1;
	                    while(k<x)
	                    {
	                        a[j+k][i]+=difference;
	                        k++;
	                    }
	                }
	                    
	            }
	        }
	        
	        if(ans(a,b,r,c)==true)
	            cout<<"YES"<<endl;
	        else
	            cout<<"NO"<<endl;
	        
	    }
	    
	    else if(r>=x  && c>=x)
	    {
	        for(int i=0;i<r;i++)
	        {
	            for(int j=0;j<(c-x+1);j++)
	            {
	                if(a[i][j]==b[i][j])
	                    continue;
	                else
	                {
	                    ll difference=b[i][j]-a[i][j];
	                    a[i][j] +=difference;
	                    ll k=1;
	                    while(k<x)
	                    {
	                        a[i][j+k] +=difference;
	                        k++;
	                    }
	                }
	            }
	        }
	        
	        for(int i=0;i<c;i++)
	        {
	            for(int j=0;j<(r-x+1);j++)
	            {
	                if(b[j][i]==a[j][i])
	                    continue;
	                else
	                {
	                    ll difference=b[j][i] - a[j][i];
	                    a[j][i] += difference;
	                    ll k=1;
	                    while(k<x)
	                    {
	                        a[j+k][i] +=difference;
	                        k++;
	                    }
	                }
	            }
	        }
	        
	        if(ans(a,b,r,c)==true)
	            cout<<"YES"<<endl;
	        else
	            cout<<"NO"<<endl;
	    }
	    
	    
	}
	return 0;
}
