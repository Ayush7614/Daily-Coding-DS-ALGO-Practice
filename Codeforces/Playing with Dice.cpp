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
    
    int a,b;
    cin>>a>>b;
    int cnt1=0,cnt2=0,cnt3=0;
    loop(i,1,7)
    {
        if(abs(a-i)<abs(b-i))
            cnt1++;
        else if(abs(a-i)>abs(b-i))
            cnt2++;
        else
            cnt3++;
    }
    cout<<cnt1<<" "<<cnt3<<" "<<cnt2<<endl;
    
    
    return 0;
}