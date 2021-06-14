package recursionProblems;

import java.util.Scanner;

public class MaxElementOfArray {

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
		int max=maxElement(arr,0);
		System.out.println(max);
		sc.close();
	}

	private static int maxElement(int[] arr, int i) {
		
		if(i==arr.length-1)
			return arr[i];
		int m1=maxElement(arr,i+1);
		if(m1>arr[i])
			return m1;
		return arr[i];
		
	}

}
