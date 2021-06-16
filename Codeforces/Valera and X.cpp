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
    unordered_set<char> a,b;
    int j=0;
    while(j<n)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(i==j  || i==n-j-1)
                a.insert(s[i]);
            else
                b.insert(s[i]);
        }
        j++;
    }
    int fir = *a.begin();
    int sec = *b.begin();
    if(a.size()==1 && b.size()==1 && fir!=sec)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    
    return 0;
}