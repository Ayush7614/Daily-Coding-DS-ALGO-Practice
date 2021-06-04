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
    vector<string> v;
    sort(s.begin(),s.end());
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<v.size()<<endl;
    sort(v.begin(),v.end());
    for(auto it:v)
        cout<<it<<endl;
    
    
    return 0;
}