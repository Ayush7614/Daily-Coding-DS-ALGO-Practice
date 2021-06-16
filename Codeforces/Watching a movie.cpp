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
    
    ll n,m;
    cin>>n>>m;
    int res=0,now=1;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
       while(now < l)
		{
			if(l - now >= m)
			{
				now += m;
			}
			else now++, res++;
		}
		res += r - l + 1;
		now = r + 1;
        
    }
    cout<<res<<endl;
    
    return 0;
}