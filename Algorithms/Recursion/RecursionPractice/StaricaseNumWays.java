package RecursionPractice;

import java.util.Scanner;

public class StaricaseNumWays {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of Stairs");
		int n=sc.nextInt();
		//YOU CAN TAKE ONE STEP or TWO STEPS at a time
		int numWays=numWays(n);
		System.out.println(numWays);

	}

	private static int numWays(int n) {
		if((n==1||n==2||n==0))
		{
			return n;
		}
			return numWays(n-1) + numWays(n-2);
	}

}


/*
 * 1->1
 * 2->2 {1,1} ,  {2}
 * 3->3 {1,1,1},{1,2},{2,1}
 * 4->5 {1,1,1,1},{1,1,2},{1,2,1},{2,1,1},{2,2}
 * 5->8 {1,1,1,1,1},{1,1,1,2},{1,1,2,1},{1,2,1,1},{2,1,1,1},{1,2,2},{2,1,2},{2,2,1}
 */



