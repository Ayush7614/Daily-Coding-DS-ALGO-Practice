// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem

#include<iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        long N;
        cin>>N;
        while(N%2==0)
            N /= 2;
        if (N==1) {
            cout<<"2"<<endl;
            break;
        }
        long i;
        for (i=3; i*i<=N; i+=2) {
            while(N%i==0) {
                N=N/i;
            }
        }
        if (N>2)
            cout<<N<<endl;
        else
            cout<<i-2<<endl;
    }
    return 0;
}
