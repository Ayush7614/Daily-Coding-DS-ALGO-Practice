package recursionProblems;

import java.util.Scanner;

public class MaxofAnArray {

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

	}

	private static int maxElement(int[] arr, int i) {
		int max=0;
		int prev=0;
		if(arr.length==1)
		{
			return arr[0];
		}
		if(i==arr.length)
		{
			return max;
		}
		max=maxElement(arr,i+1);
		if(i>0)
			prev=arr[i-1];
		if(max>prev&&max>arr[arr.length-1])
		{
			//System.out.print(arr[arr.length-1]);
			return max;
		}
		else
		{
			if(prev>arr[arr.length-1])
			{
				return prev;
			}
			else
			{
				return arr[arr.length-1];
			}
		}
		
		
	}

}
