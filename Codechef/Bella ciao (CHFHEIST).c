#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        long long int D;
        long long int d;
        long long int p;
        long long int q;
        long long int total = 0;
        long long int r = 0;
        scanf("%lld %lld %lld %lld", &D, &d, &p, &q);
        r = D/d;
        if(D%d==0)
        {
            total += (d) * p * (r) + q * ((r)*(r - 1)*(d)/2);
        }
        else
        {
            total += (d) * p * (r) + q * ((r)*(r - 1)*(d)/2);
            total += (D%d) * p + (D-r*d) * q * (r);
        }
        printf("%lld\n", total);
    }
 return 0;
}