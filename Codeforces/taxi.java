import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class taxi
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    int n;
	    int count[]=new int[5];
	    n=sc.nextInt();
    while (n--!=0)
    {
        int s=sc.nextInt();
        count[s] += 1;
    }
    int total = count[4] + count[3] + count[2] / 2;
    count[1] -= count[3];
    if (count[2] % 2 == 1)
    {
        total += 1;
        count[1] -= 2;
    }
    if (count[1] > 0)
    {
        total += (count[1] + 3) / 4;
    }
    System.out.println(total);
	}
}

/* 
input-
5
1 2 4 3 3
Output-
4
*/
