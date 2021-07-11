#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>x;
    vector<pair<int,int>>y;
    multiset<int>X;
    multiset<int>Y;
   
    for(int i=0;i<n;i++)
    {
        int a;int b;cin>>a>>b;
        x.push_back({a,b});
        y.push_back({b,a});
        X.insert(a);
        Y.insert(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int maxh1=0;
    int minh1=LLONG_MAX;
    int h1=0;int h2=0;
    int area=LLONG_MAX;
   
    for(int i=0;i<n-1;i++)
    {
        maxh1=max(maxh1,x[i].second);
        minh1=min(minh1,x[i].second);
        h1=maxh1-minh1;
        auto it=Y.find(x[i].second);
        Y.erase(it);
        h2=*(Y.rbegin())-*(Y.begin());
        int narea=(x[i].first-x[0].first)*h1;
        narea+=((x[n-1].first-x[i+1].first)*h2);
       
        area=min(area,narea);
    }
    maxh1=0;
    minh1=LLONG_MAX;
    h1=0;
    h2=0;
    for(int i=0;i<n-1;i++)
    {
        maxh1=max(maxh1,y[i].second);
        minh1=min(minh1,y[i].second);
        h1=maxh1-minh1;
        auto it=X.find(y[i].second);
        X.erase(it);
        h2=*(X.rbegin())-*(X.begin());
        int narea=(y[i].first-y[0].first)*h1;
        narea+=((y[n-1].first-y[i+1].first)*h2);
       
        area=min(area,narea);
    }
    if(area==LLONG_MAX)
    area=0;
    cout<<area<<endl;
   
}
int main()
{
rapido;
int t=1;
cin>>t;
while(t--)
solve();
return 0;
}

/* TEST CASE
SAMPLE INPUT
3
1
100 100
4
1 100
100 100
100 1
1 1
5
1 100
100 100
100 1
1 1
50 50

SAMPLE OUTPUT:
0
0
4851 */

