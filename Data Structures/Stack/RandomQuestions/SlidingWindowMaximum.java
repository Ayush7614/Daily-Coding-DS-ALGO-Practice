package RandomQuestions;

import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class SlidingWindowMaximum {
	
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size");
		int n=sc.nextInt();
		int a[]=new int[n];
		System.out.println("Enter "+n+" elements");
		for(int i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
		}
		System.out.println("Enter window size");
		int k=sc.nextInt();
		int[] nextGreater=new int[a.length];
		sc.close();
		Stack<Integer> st=new Stack<>();
		
		st.push(a.length-1);
		nextGreater[a.length-1]=a.length;
		
		for(int i=a.length-2;i>=0;i--) 
		{
			while(st.size()>0 && a[i]>=a[st.peek()])
			{
				st.pop();
			}
			
			if(st.size()==0) {
				nextGreater[i]=a.length;
			}
			else
			{
				nextGreater[i]=st.peek();
			}
			st.push(i);
		}
		
		for(int i=0;i<=a.length-k;i++)
		{
			int j=0;
			while(nextGreater[j]<i+k)
			{
				j=nextGreater[j];
			}
		}
		for(int i=0;i<nextGreater.length;i++)
		{
			System.out.print(nextGreater[i]+" ");
		}
		
	}

}
