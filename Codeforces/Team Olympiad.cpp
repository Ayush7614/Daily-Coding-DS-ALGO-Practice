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
    int count1=0,count2=0,count3=0;
    vector<pair<int,bool>> v;
    loop(i,0,n)
    {
        int x;
        cin>>x;
        if(x==1)    count1++;
        if(x==2)    count2++;
        if(x==3)    count3++;
        v.push_back(make_pair(x,false));
    }
    int w=min(count1,min(count2,count3));
    cout<<w<<endl;
    
    while(w--)
    {
        count1=count2=count3=1;
    for(int i=0;i<n;i++)
    {
        if(v[i].first==1 && v[i].second==false && count1!=0 )
        {
            cout<<i+1<<" ";
            v[i].second=true;
            count1=0;
        }
        else if(v[i].first==2 && v[i].second==false && count2!=0 )
        {
            cout<<i+1<<" ";
            v[i].second=true;
            count2=0;
        }
        else if(v[i].first==3 && v[i].second==false && count3!=0 )
        {
            cout<<i+1<<" ";
            count3=0;
            v[i].second=true;
        }
    }
    cout<<endl;
    }
    
    return 0;
}