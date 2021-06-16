#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPrime(int x)
{
    if(x%2==0)
    return false;
    bool flga=false;
    for(int i=3;i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    bool flag=false;
    for(int i=n+1;i<=m;i++)
    {
        if(isPrime(i)==true && i==m){
            cout<<"YES"<<endl;
            flag=true;
        }
        
    }
    if(flag=false)
        cout<<"NO"<<endl;
    
    
    
    return 0;
}