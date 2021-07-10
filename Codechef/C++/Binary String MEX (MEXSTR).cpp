#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using ll = long long;
using ld = long double ;
using cmpl = complex<long double>;
constexpr int MAXN =(int)1e6;
int dp[MAXN+2],dp1[MAXN+2];
int next0[MAXN];
int next1[MAXN];

void spar()
{
    string s;
    cin>>s;
    int n=s.length();
    int last_pos =-1;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            for(int j=last_pos+1;j<=i;++j)
            
                next0[j]=i;
            last_pos=i;
                
            
        }
    }
    
    for(int i=last_pos+1;i<n;++i)
        next0[i]=n;
    if(next0[0]==n)
    {
        cout<<"0"<<endl;
        return ;
    }
    last_pos =-1;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1'){
            for(int j=last_pos+1;j<=i;++j)
            next1[j]=i;
        last_pos=i;
        }
    }
    
    for(int i=last_pos+1;i<n;++i)
    next1[i]=n;
    
    dp[n]=dp[n+1]=0;
    dp1[n]=dp1[n+1]=0;
    for(int i=n-1;i>=0;--i)
    {
        dp[i]=dp[i+1];
        if(s[i]=='0'  && next1[i]<n)
        dp[i]=max(dp[i],dp[next1[i]+1]+1);
        if(s[i]=='1' && next0[i]<n)
        dp[i]=max(dp[i],dp[next0[i]+1]+1);
        dp1[i]=dp1[i+1];
        if(next1[i]<n)
        dp1[i]=max(dp1[i],dp[next1[i]+1]+1);
        
    }
    
    int len =dp1[0]+1;
    int curind = next1[0]+1;
    string ans="1";
    for(int i=1;i<len;++i)
    {
        if(curind >=n)
        {
            ans.push_back('0');
            continue;
        }
        if(next0[curind] >=n)
        {
            ans.push_back('0');
            curind = next0[curind]+1;
            continue;
        }
        
        if(dp[next0[curind]+1] < len-i-1)
        {
            ans.push_back('0');
            curind = next0[curind]+1;
            
        }
        else
        {
            ans.push_back('1');
            curind =next1[curind]+1;
        }
    }
    cout<<ans<<endl;
    
    
}


int main(int argc,char *argv[] )
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","r",stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    if(argc>1)
        freopen(argv[1],"r",stdin);
    if(argc >2)
        freopen(argv[2],"w",stdout);
        
        int t;
        cin>>t;
        while(t--)
        {
            spar();
            
        }
        return 0;
}


