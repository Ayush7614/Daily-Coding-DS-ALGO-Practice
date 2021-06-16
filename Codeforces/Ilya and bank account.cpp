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
    if(n>=0)
        cout<<n<<endl;
    else
    {
        string s=to_string(n);
        string temp=s;
        int n=s.length()-1;
        s.erase(s.begin()+n);
        n=n-1;
        if(temp.length()>=2)
            temp.erase(temp.begin()+n);
        int a=stoi(s);
        int b=stoi(temp);
        cout<<max(a,b)<<endl;
    }
    
    
    
    return 0;
}