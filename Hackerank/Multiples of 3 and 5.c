// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem

#include <stdio.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n; 
        scanf("%ld",&n);
        long k, sum=0;
        k = (n-1)/3;
        sum = sum + 3*k*(k+1)/2;
        k = (n-1)/5;
        sum = sum + 5*k*(k+1)/2;
        k = (n-1)/15;
        sum = sum - 15*k*(k+1)/2;
        printf("%ld\n", sum);
    }
    return 0;
}
