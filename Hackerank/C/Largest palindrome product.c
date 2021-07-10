// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <stdio.h>

int palindrome (long N) {
    long reversedInteger = 0, remainder, originalInteger;

    originalInteger = N;

    // reversed integer is stored in variable 
    while( N!=0 )
    {
        remainder = N%10;
        reversedInteger = reversedInteger*10 + remainder;
        N /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal
    if (originalInteger == reversedInteger)
        return 1;
    else
        return 0;
}

int isfactor(long N) {
    int i;
    for (i=999; i>=100; i--) {
        if (N%i == 0) {
            if (N/i < 999 && N/i > 100) {
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n, i; 
        scanf("%ld",&n);
        for(i=n-1; i>=1; i--) {
            if (palindrome(i) && isfactor(i)) {
                printf("%ld\n", i);
                break;
            }
        }
        
    }
    return 0;
}