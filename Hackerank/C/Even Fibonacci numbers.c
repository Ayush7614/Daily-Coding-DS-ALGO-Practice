// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem

#include <stdio.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n; 
        scanf("%ld",&n);
        long prev=1, curr=2, next=0, sum=0;
        while (next<n) {
            if (curr%2 == 0) {
                sum = sum + curr;
            }
            next = prev+curr;
            prev = curr;
            curr = next;
        }
        printf("%ld\n", sum);
    }
    return 0;
}