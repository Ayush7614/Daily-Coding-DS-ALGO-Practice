import java.util.*;
import java.lang.*;
import java.io.*;


class bella
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	 long t;
	  t=sc.nextLong();
	while(t--!=0)
	{
	    long d,D,P,Q,sum=0;
	     D=sc.nextLong();
	     d=sc.nextLong();
	     P=sc.nextLong();
	     Q=sc.nextLong();
	    long k=D/d;
	     if(D%d==0)
	     {
	         sum+=d*(P*k+(k*(k-1)/2)*Q);
	     }
	     else
	     {
	         sum+=d*(P*k+(k*(k-1)/2)*Q);
	         sum+=(D%d)*(P+(k*Q));
	     }
	    System.out.println(sum);
	    
	}
	
	}
}

/* 
Input-
3
2 1 1 1
3 2 1 1
5 2 1 2
Output-
3
4
13
*/
