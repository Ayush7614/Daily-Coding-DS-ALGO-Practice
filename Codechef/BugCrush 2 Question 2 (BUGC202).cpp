#include <stdio.h>
#include <math.h>
void is_armstrong(int number)
{
     int num, lastDigit, digits, sum, i;


   

    for(i=0; i<=number; i++)
    {
        sum = 0;

       
        num = i;

       
        digits = (int) log10(num) + 1;

       
        while(num > 0)
        {
           
            lastDigit = num % 10;

            
            sum = sum + ceil(pow(lastDigit, digits));

           
            num = num / 10;
        }

        
        if(i == sum)
        {
            printf(" %d", i);
        }

    }
  
}
int main() {
	int x;
  scanf("%d",&x);
  is_armstrong(x);
	return 0;
}