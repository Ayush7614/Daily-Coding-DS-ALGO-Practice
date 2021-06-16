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
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    ll a[128]={0};
    ll b[128]={0};
    loop(i,0,s1.length())
    {
        if(s1[i]==' ')
            continue;
        a[s1[i]]++;
    }
    loop(i,0,s2.length())
    {
        if(s2[i]==' ')
            continue;
        b[s2[i]]++;
    }
    bool flag = false;
    loop(i,0,128)
    {
        if(b[i]>a[i])
        {
            flag=true;
            break;
        }
        
    }
    if(flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    
    return 0;
}