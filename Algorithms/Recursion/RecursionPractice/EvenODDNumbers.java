package RecursionPractice;

import java.util.Scanner;

public class EvenODDNumbers {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter n");
		int n=sc.nextInt();
		System.out.println("Even Nos:");
		evenNums(n);
		System.out.println("Odd Nos:");
		oddNums(n);
	}

	private static void oddNums(int n) {
		
		if(n==-1)
		{
			return;
		}
		if(n%2!=0)
		{
			System.out.println(n);
			oddNums(n-1);
		}
		else
		{
			oddNums(n-1);
		}
		
		
	}

	private static void evenNums(int n) {
		if(n==-1)
		{
			return;
		}
		if(n%2==0)
		{
			System.out.println(n);
			evenNums(n-1);
		}
		else
		{
			evenNums(n-1);
		}
		
	}

}
