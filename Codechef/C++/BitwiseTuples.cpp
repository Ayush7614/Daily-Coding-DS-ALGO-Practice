//Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2^M−1 
//and A1&A2&…&AN=0, where & denotes the bitwise AND operator.Since the number of tuples can be large, output it modulo (10^9)+7.
/*

Sample Input :

4
1 2
2 2
4 2
8 4

Sample Output :

1
9
225
228250597

*/

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll power(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b%2){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll N,M,x;
        cin>>N>>M;
        x=power(2,N)-1;
        x=power(x,M);
        cout<<x<<endl;
    }
}