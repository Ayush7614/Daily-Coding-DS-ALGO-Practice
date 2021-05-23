#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char s[1001];
    scanf("%[^\n]%*c", s);
    int arr[10] = {0};
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= '0' && s[i] <= '9')
            arr[s[i] - '0']++;
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
