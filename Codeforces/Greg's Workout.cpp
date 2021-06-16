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
    
    ll n;
    cin>>n;
    ll chest=0,back=0,bicpes=0;
    ll count=n/3 + 1;
    while(count--)
    {
        ll a=0,b=0,c=0;
        cin>>a>>b>>c;
        chest+=a;
        bicpes+=b;
        back+=c;
    }
    if(chest>bicpes && chest>back)
        cout<<"chest"<<endl;
    else if(bicpes>chest && bicpes>back)
        cout<<"biceps"<<endl;
    else
        cout<<"back"<<endl;
    return 0;
}