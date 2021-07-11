#include<iostream>
#include<algorithm>
using namespace std;

bool comp(int a, int b)   
{   
    return (a < b);   
}   

int main(){
    int T, d, x, y, z;
    cin >> T;
    
    while(T--){
       cin>>d>>x>>y>>z;
       cout<<max({7*x, y*d + (7-d)*z},comp)<<endl;
    }
}