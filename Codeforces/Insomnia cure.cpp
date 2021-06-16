#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<=(b);i++)
#define ff first
#define ss second
#define vi vector<int>


unordered_set<int> s;
ll d;

void insomnia(ll value)
{
    for(int i=1;i<=d;i++)
    {
        if(i%value==0)
        s.insert(i);
        else 
        continue;
    }
    return ;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k,l,m,n;
    cin>>k>>l>>m>>n>>d;
    insomnia(k);
    insomnia(l);
    insomnia(m);
    insomnia(n);
    cout<<s.size()<<endl;
    
    
    
    
    
    return 0;
}