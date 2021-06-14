package recursionProblems;

import java.util.Scanner;

public class PowerFunc {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter x");
		int x=sc.nextInt();
		System.out.println("Enter n");
		int n=sc.nextInt();
		sc.close();
		int res=power(x,n);
		System.out.println(res);

	}

	private static int power(int x, int n) {
		if(n==0)
		{
			return 1;
		}
		int f=x*power(x,n-1);
		return f;
		
	}

}
