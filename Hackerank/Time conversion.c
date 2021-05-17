#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[20];
    scanf("%s",s);
    if(s[strlen(s)-2]=='P' || s[strlen(s)-2]=='p')
    {
        if(!(s[0]=='1' && s[1]=='2'))
        {
            
            s[0]=s[0]+1;
            s[1]=s[1]+2;
        }
    }
    else if(s[strlen(s)-2]=='A' || s[strlen(s)-2]=='a')
    {    
        if(s[0]=='1' && s[1]=='2')
        {
                s[0]='0';
                s[1]='0';
        }
    }
    s[strlen(s)-2]='\0';
        printf("%s",s);   
    return 0;
}
