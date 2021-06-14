package RecursionPractice;
import java.util.Scanner;

public class mazeProblem {

	public static void main(String[] args) {
		System.out.println("Enter m and n");
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		sc.close();
		int res=totalMazePaths(m,n);
		System.out.println(res);

	}

	private static int totalMazePaths(int m, int n) {
		if(m==1||n==1)
		{
			return 1;
		}
		else
		{
			return totalMazePaths(m-1,n) + totalMazePaths(m,n-1);
		}
	}

}
