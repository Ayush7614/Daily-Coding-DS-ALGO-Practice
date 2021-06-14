package recursionProblems;

import java.util.Scanner;

public class LogarithmicPower {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter x-");
		int x=sc.nextInt();
		System.out.println("Enter n-");
		int n=sc.nextInt();
		sc.close();
		int res=LogPower(x,n);
		System.out.println(res);
		
		/*
		 * Basic Idea:
		 * 
		 * pow(x,n)=pow(x,n/2) * pow(x,n/2) ,iff n is even
		 * eg:pow(2,2)=pow(2,1) * pow(2,1) ->gives 4
		 * 
		 * pow(x,n)=pow(x,n/2) * pow(x,n/2) * x ,iff n is odd
		 * eg:pow(2,3)=pow(2,1) * pow(2,1) * 2 ->4*2 gives 8
		 * 
		 */


	}

	private static int LogPower(int x, int n) {
		if(n==0)
		{
			return 1;
		}
		if(n%2==0)
		{
			return LogPower(x,n/2)*LogPower(x,n/2);
		}
		else
		{
			return LogPower(x,n/2)*LogPower(x,n/2)*x;
		}
	}

}
