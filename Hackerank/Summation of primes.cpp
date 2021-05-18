// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem

#include <bits/stdc++.h> 
using namespace std; 
 
void sumOfPrimes(int n) {
    bool prime[n + 1];
    long sum[n+1];
    memset(prime, true, n + 1);
    sum[0] = 0;
    sum[1] = 0;
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int i = 2; i <= n; i++) 
        if (prime[i]) 
            sum[i] = sum[i-1]+i;
        else
            sum[i] = sum[i-1];
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        cout<<sum[N]<<endl;
    }
} 
int main() 
{ 
    int n=1000000;
    sumOfPrimes(n); 
    return 0; 
}
