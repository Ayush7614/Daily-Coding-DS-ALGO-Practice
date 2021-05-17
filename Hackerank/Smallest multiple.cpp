// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler005/problem

#include <stdio.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        long i;
        int j;
        for (i=1; ; i++) {
            for (j=1; j<=n; j++) {
                if (i%j != 0) {
                    break;
                }
            }
            if (j == n+1) {
                printf("%ld\n", i);
                break;
            }
        }
    }
    return 0;
}