// Question  https://www.codechef.com/START7C/problems/FODCHAIN

// Examples
/**
 * Sample Input 1 
 * 3
 * 5 3
 * 6 7
 * 10 2
 * 
 * Sample Output 1 
 * 2
 * 1
 * 4
 */

 // Solution

 /* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		try {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
			int a=sc.nextInt();
			int b=sc.nextInt();
			//System.out.println(Math.floorDiv(a, b)+1);
			//int ans=0;
			int count=0;
			while(a!=0)
			{
				 a=Math.floorDiv(a, b);
				 count++;
			}
			System.out.println(count);
			
			
		}
		sc.close();
		}
		catch(Exception e)
		{
			
		}
	}
}
