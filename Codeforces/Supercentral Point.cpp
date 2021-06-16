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
    ll n;
    cin>>n;
    ll x[n],y[n];
    loop(i,0,n)
        cin>>x[i]>>y[i];
    bool left=0,right=0,upper=0,lower=0;
    ll count =0;
    for(int i=0;i<n;i++)
    {
        upper=0,lower=0,right=0,left=0;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            else if(x[i]>x[j] && y[i]==y[j])
                right=1;
            else if(x[i]< x[j] && y[i]==y[j])
                left=1;
            else if(x[i]==x[j] && y[i] > y[j])
                lower=1;
            else if(x[i]==x[j] && y[i]<y[j])
                upper=1;
        }
        if(upper&&lower&&right&&left){
            count+=1;
           
        }    
        else 
            continue;
    }
    cout<<count<<endl;
    
    
    
    return 0;
}