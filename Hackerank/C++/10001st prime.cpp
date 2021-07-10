// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void sieve(int n) {
    vector <bool> prime;
    vector <int> nth;
    prime.resize(n+1);
    nth.resize(10002);
    for(int i=0; i<=n; i++) {
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    nth[0]=0;
    int k=1;
    for (int i=2; i*i<=n; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=n; j=j+i) {
                prime[j] = false;
            }
        }
    }
    for(int i=0; i<=n, k<10002; i++) {
        if(prime[i]) {
            nth[k]=i;
            k++;
        }
    }
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        cout<<nth[N]<<endl;
    }
}

int main() {
    int n=1000000;
    sieve(n);
    return 0;
}
