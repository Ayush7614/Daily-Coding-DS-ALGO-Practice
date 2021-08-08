//Problem link : https://www.codechef.com/problems/HS08TEST

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
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble();
		double amnt = sc.nextDouble();
		if(amnt >= x+0.5){
		    if(x%5 == 0){
		        amnt = amnt-x-0.5;
		    }
		}
		System.out.println(amnt);
	}
}

//
// Example test case
// Input:
// 42 120.00
//
// Output:
// 120.00
//
// Input:
// 300 120.00
//
// Output:
// 120.00
