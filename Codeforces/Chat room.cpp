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
    string s;
    cin>>s;
    int j=0;
    string h = "hello";
    for(int i=0;i<s.length()&&j<h.length();i++)
    {
        if(s[i]==h[j])
            j++;
    }
    (j==h.length())?cout<<"YES"<<endl:cout<<"NO"<<endl;
    
    
    return 0;
}