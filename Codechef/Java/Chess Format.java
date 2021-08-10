// Question  https://www.codechef.com/problems/CHSFORMT

// Example
/**
 * Sample Input 1 
 * 4
 * 1 0
 * 4 1
 * 100 0
 * 20 5
 * 
 * Sample Output 1 
 * 1
 * 2
 * 4
 * 3
 */

 // Solution 

 
import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{


Scanner sc=new Scanner(System.in);
int t=sc.nextInt();
for(int y=0;y<t;y++){
   int a=sc.nextInt();
    int b=sc.nextInt();
    int c=a+b;
    if(c<3){
        System.out.println("1");
    }
      else if(c>=3&&c<=10){
        System.out.println("2");
    }
    
      else if(c>=11&&c<=60){
        System.out.println("3");
    }
    
      else if(c>60){
        System.out.println("4");
    }

}

	
	}
}
