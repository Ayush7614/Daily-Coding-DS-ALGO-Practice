/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 0 ; t < test ; t++){
		    int qty = sc.nextInt();
		    double price = sc.nextInt();
		    if (qty > 1000){
		        System.out.println(qty*price-0.1*qty*price);
		    }
		    else{
		        System.out.println(qty*price);
		    }
		}
	}
}
