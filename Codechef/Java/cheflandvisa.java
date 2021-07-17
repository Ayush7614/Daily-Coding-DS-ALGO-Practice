import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
     Scanner sc=new Scanner(System.in);
	 long t=sc.nextLong();//Inputting the total testcases
	while(t--!=0)
	{
	    long x1,x2,y1,y2,z1,z2;
	    x1=sc.nextLong();
	    x2=sc.nextLong();
	    y1=sc.nextLong();
	    y2=sc.nextLong();
	    z1=sc.nextLong();
	    z2=sc.nextLong();
	    if(x2>=x1 && y2>=y1 && z2<=z1)//Checking the condition
	     System.out.println("YES");
	    else
	    System.out.println("NO");
	}

}
	}

/*
Input-
4
20 50 2100 1900 6 6
50 20 1900 1900 5 5
20 20 1900 1900 1 6
27 27 1920 1920 3 3
Output-
NO
NO
NO
YES
*/
