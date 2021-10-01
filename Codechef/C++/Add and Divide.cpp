#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double db;
long long int M = 1e9 + 7;
long long int inf = 9 * 1e18;

//for finding out prime factors
vector<int> solve(int a){
    vector<int>v;
    while(a!=1 && a%2==0){
        v.push_back(2);
        a/=2;
    }
    int i;
    for(i=3;i<=sqrt(a);i+=2){
        while(a!=1 && a%i==0){
             v.push_back(i);
        a/=i;
        }
    }
    if(a>2)v.push_back(a);
    return v;
    
}


int main()
{
    ll t=1;
    cin >> t;
    while(t--)
    {
    ll a,b;
    cin>>a>>b;
    vector<int> v=solve(a);
    bool done=true;
    for(int i=0;i<v.size();i++){
        if(b%v[i]!=0) {
            done=false;
            cout<<"no"<<endl;
            break;
        }
    }
    if(done)cout<<"yes"<<endl;
    }

    return 0;
}
