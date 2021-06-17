/*

Armstrong Number

Example 1:
153 = (1*1*1)+(5*5*5)+(3*3*3) 
    = 1 + 125 + 9  = 153
153 is an Armstrong number

Example 2:
371 = (3*3*3)+(7*7*7)+(1*1*1)  
    = 37 + 343 + 1  = 371
    
*/

public class Main{  
  public static void main(String[] args)  {  
    int c=0,a,temp;  
    int n=153;
    temp=n;

    while(n>0)  {  
        a = n%10;  
        n = n/10;  
        c = c+(a*a*a);  
    } 

    if(temp == c)  
        System.out.println(temp + " is an Armstrong number");   
    else  
        System.out.println(temp + "is not an armstrong number");   
   }  
}  
