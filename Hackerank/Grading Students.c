#include<stdio.h>
int main() {
  int n, e = 0;
  scanf("%d",&n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d",&a[i]);
  }
  for (int i = 0; i < n; i++) {

    if (a[i] >= 38) {

      for (int j = a[i]; e != 1; j++) {
        if (j % 5 == 0) {
          if (j - a[i] < 3) {
            a[i] = j;
          } else if (j - a[i] == 3) {
            a[i] = a[i];
          }
          e = 1;
        }
      }
      e = 0;

    }

    else {
      a[i] = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n",a[i]);
  }
}
