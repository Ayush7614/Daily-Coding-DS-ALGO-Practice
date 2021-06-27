#include <stdio.h>

int main(void) {
  // your code goes here
  int t;
  scanf("%d",&t);
  while(t--){
      long long int a,b;
        scanf("%lld%lld",&a,&b);
        if((b&(b-1))==0)
            printf("Yes\n");
        else
            printf("No\n");
  }
  return 0;
}