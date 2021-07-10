// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler017/problem

#include <stdio.h>
char digits[20][10] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
char tens[11][10] =  {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

void word(int num){
    if(num/100)
        printf("%s Hundred ", digits[num/100]);
    if((num%100) < 20 && (num%100) > 0)
        printf("%s ",digits[num%100]);
    else if((num/10)%10){
        printf("%s ", tens[(num/10)%10]);
        if(num%10)
            printf("%s ", digits[num%10]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        long long int num;
        scanf("%lld", &num);
        int tn = num / 1000000000000;
        int bn = (num / 1000000000) % 1000;
        int mn = (num / 1000000) % 1000;
        int th = (num / 1000) % 1000;
        int hd = num % 1000;
        //printf("%d %d %d %d %d\n", tn, bn, mn, th, hd);
        if((tn + bn + mn + th + hd) == 0)
            printf("Zero");
        if(tn){
            word(tn);
            printf("Trillion ");
        }
        if(bn){
            word(bn);
            printf("Billion ");
        }
        if(mn){
            word(mn);
            printf("Million ");
        }
        if(th){
            word(th);
            printf("Thousand ");
        }
        if(hd){
            word(hd);
        }
       printf("\n"); 
    }
    return 0;
}
