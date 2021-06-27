/*
Link to problem- https://www.codechef.com/START5C/problems/TOTCRT
*/

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class total
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t--!=0)
		{
		    int n=sc.nextInt();
		  HashMap<String,Integer> ma=new HashMap<String,Integer>();
		  ma.put(sc.next(),sc.nextInt());
		  for(int i=1;i<(n*3);i++)
		  {
		      String s=sc.next();
		      int a=sc.nextInt();
		      if(ma.containsKey(s))
		      {
		          ma.replace(s,ma.get(s)+a);
		      }
		      else
		      ma.put(s,a);
		  }
		  List<Integer> li=new ArrayList<Integer>(ma.values());
		  Collections.sort(li);
		  for(Integer i:li)
		  System.out.print(i+" ");
		  System.out.println();
		}
	}
}

/* 
Input-
3
1
A 1
B 2
C 3
2
AA 1
AB 1
AB 1
AC 1
AC 1
AD 1
1
Z 100
Z 100
Z 100
Output-
1 2 3
1 1 2 2
300
*/
