#include<bits/stdc++.h>
using namespace std;
long long int mpow(long long int);
int main()
{
    long long int t,n,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        b=mpow(n);
        cout<<b/2<<endl;
    }
}
