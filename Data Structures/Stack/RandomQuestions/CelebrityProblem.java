package RandomQuestions;

import java.util.Scanner;
import java.util.Stack;

public class CelebrityProblem {

	public static void main(String[] args) {
		
		/*
		 * Given 5*5 matrix
		 * Identify a celebrity
		 * celebrity definition:
		 *                 known by everybody
		 *                 knows nobody
		 *                 
		 * atmost there will be only one celebrity.
		 * 
		 * 
		 * knowing someone is indicated by a 1 in matrix
		 * not knowing someone is indicated by a 0 in matrix.
		 *
		 *	             0    1    2    3     4
		 *
		 *			0	 0    0    1	1	  0
		 *			1    1    0    1    0     1
		 *			2    0    0    0    0     0
		 *			3    1    1    1    0     0
		 *			4    0    1    1    0     0
		 *
		 *         If above matrix in given as input, 2 will be a celebrity.
		 *
		 */
		
		Scanner sc=new Scanner(System.in);
		int arr[][]=new int[5][5];
		int a;
		int b;
		for(a=0;a<5;a++) 
			for(b=0;b<5;b++)
				arr[a][b]=sc.nextInt();
			sc.close();
			findCelebrity(arr);
		}

	private static void findCelebrity(int[][] arr) 
	{
		Stack<Integer> st=new Stack<>();
		for(int i=0;i<arr.length;i++)
		{
			st.push(i);
		}
		while(st.size()>=2)
		{
			int i=st.pop();
			int j=st.pop();
			
			if(arr[i][j]==1)
			{
				//i is not celebrity
				st.push(j);
			}
			else
			{
				//j is not celebrity
				st.push(i);
			}
		}
		
		int potCeleb=st.pop();  //potential celebrity
		for(int i=0;i<arr.length;i++)
		{
			if(i!=potCeleb)
			{
			    //known by everybody and knows nobody
				if(arr[i][potCeleb]==0||arr[potCeleb][i]==1)
				{
					System.out.println("No Celebrity");
					System.exit(0);
				}
			
			}
		}
		System.out.println("Celebrity is "+potCeleb);
		
	}

}
