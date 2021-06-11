#include <stdio.h>

int main(void) {
	int length,breadth,a,p;
    	scanf("%d",&length);
	    scanf("%d",&breadth);
 a = length*breadth;
 p = 2*(length+breadth);

 if(p>a)
     {
          printf("Peri\n");
          printf("%d",p);
     }
     else if(p<a)
     {
          printf("Area\n");
          printf("%d",a);
     }
     else
     {
          printf("Eq\n");
          printf("%d",a);
     }
	return 0;
}

