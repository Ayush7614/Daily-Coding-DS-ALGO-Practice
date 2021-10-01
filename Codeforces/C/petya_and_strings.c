#include <stdio.h>
#include <string.h>
int main () 
{
    char strone[100];
    char strtwo[100];
    
    scanf("%s",strone);
    scanf("%s",strtwo);
    for ( int i = 0; strone[i]!='\0'; i++) {
   if(strone[i] >= 'a' && strone[i] <= 'z') {
      strone[i] = strone[i] -32;
   }
}
for ( int i = 0; strtwo[i]!='\0'; i++) {
   if(strtwo[i] >= 'a' && strtwo[i] <= 'z') {
      strtwo[i] = strtwo[i] -32;
   }
}
    if ( strcmp(strone,strtwo) == 0 ) {
        printf("%d",0);
    }
else if ( strcmp(strone,strtwo) > 0 ) {
    printf("%d",1);
}
else {
    printf("%d",-1);
}
    
}