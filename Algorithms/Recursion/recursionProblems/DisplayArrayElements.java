package recursionProblems;

import java.util.Scanner;

public class DisplayArrayElements {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter n");
		int n=sc.nextInt();
		int index;
		int[] arr=new int[n];
		for(index=0;index<n;index++)
		{
			arr[index]=sc.nextInt();
		}
		DAE(arr,0);

	}

	private static void DAE(int[] arr, int index) {
	
		if(index==arr.length)
		{
			return;
		}
		System.out.println(arr[index]);
		
		DAE(arr,index+1);
		
	}

}
