#include <stdio.h>
 
int main()
{
    int t;
    scanf(%d,&t);
 
    while(t--){
        
        int n;
        cin >> n;
        if(n % 2 == 1){
            printf("Bob\n");
            continue;
        }
        int cnt = 0;
        while(n % 2 == 0){
            cnt++;
            n /= 2;
        }
 
        if(n > 1){
            printf("Alice\n");
        }else if(cnt % 2 == 0){
            printf("Alice\n");
        }else printf("Bob\n");
    }
}

