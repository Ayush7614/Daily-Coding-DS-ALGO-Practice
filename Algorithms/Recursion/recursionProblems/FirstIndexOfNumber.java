package recursionProblems;

import java.util.Scanner;

public class FirstIndexOfNumber {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter n");
		int n=sc.nextInt();
		int arr[]=new int[n+1];
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		System.out.println("Enter number to be searched");
		int data=sc.nextInt();
		int firstIndex=firstIndex(arr,0,data);
		System.out.println(firstIndex);
	}

	private static int firstIndex(int[] arr, int i, int data) {
		if(arr[i]==arr.length-2)
		{
			return arr[i];
		}
		int fiisa=firstIndex(arr,i+1,data);
		if(arr[i]==data)
			return i;
		return fiisa;
	}

}
