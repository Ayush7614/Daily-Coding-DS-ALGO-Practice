// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem

#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout<<(n-1)*n*(n+1)*(3*n+2)/12<<"\n";
    }
    return 0;
}