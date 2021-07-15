import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class CovidAnalyzer
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		long arr[]=new long[90];
		arr[0]=1;
		arr[1]=2;
		for(int i=2;i<90;i++)
		{
		    arr[i]=arr[i-1]+arr[i-2];
		}
		for(int l=0;l<t;l++)
		{
		    int x=sc.nextInt();
		    System.out.println(arr[x-1]);
		}
	}
}
