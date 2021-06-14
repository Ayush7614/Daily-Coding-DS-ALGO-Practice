package RandomQuestions;

import java.util.Stack;

public class EqualStacks {

	public static void main(String[] args) {
		
		Stack<Integer> s1=new Stack<>();
		Stack<Integer> s2=new Stack<>();
		Stack<Integer> s3=new Stack<>();
		
		s1.add(3);s1.add(2);s1.add(1);s1.add(1);s1.add(1);s1.add(3);
		s2.add(4);s2.add(2);
		s3.add(1);s3.add(1);s3.add(1);s3.add(4);
		
		/*
		 * should return height as 6:
		 *      remove 3 from stack1 -> 2+1+1+1+3=8
		 *      Remove 2 from stack1 -> 1+1+1+3=6
		 *      Remove 1 from stack3 -> 1+1+4=6
		 *      
		 *      there is no need to change stack2 [sum=6]
		 *      
		 *      so,return 6
		 */
		int height=lowestEqualHeight(s1,s2,s3);
		System.out.println("Height="+height);

	}

	private static int lowestEqualHeight(Stack<Integer> s1, Stack<Integer> s2, Stack<Integer> s3) 
	{
		int sum1=0;
		int sum2=0;
		int sum3=0;
		for(int i=0;i<s1.size();i++)
		{
			sum1+=s1.get(i);
		}
		for(int i=0;i<s2.size();i++)
		{
				sum2+=s2.get(i);
		}
		for(int i=0;i<s3.size();i++)
		{
			try
			{
				sum3+=s3.get(i);
			}
			catch(Exception ArrayIndexOutOfBoundsException)
			{
				sum3+=0;
			}
		}
		
		int i=0,j=0,k=0;
		while(!(sum1==sum2 && sum2==sum3))
		{
			if(sum1>sum2 && sum1>sum3)
			{
				sum1-=s1.get(i);
				i++;
			}
			else if(sum2>sum1 && sum2>sum3)
			{
				sum2-=s2.get(j);
				j++;
			}
			else
			{
				try
				{
					sum3-=s3.get(k);
				}
				catch(Exception ArrayIndexOutOfBoundsException)
				{
					sum3-=0;
				}
				k++;
			}
		}
		return sum1;
	}
}


/*
 * 
 * Debug:
 * 
 * 
 * System.out.println("Removed "+s1.get(i)+" stack 1");
 * 
 * System.out.println("Removed "+s2.get(j)+" stack 2");
 * 
 * System.out.println("Removed "+s3.get(k)+" stack 3");
 * 
 * 
3
5
6
7
8
11
*********************************
0
4
4
6
***********************************
--------------------
11
6
7
--------------------
11
Removed 3 stack 1

//////////////////////
8
6
7
/////////////////////////
 * 
--------------------
8
6
7
--------------------
8
Removed 2 stack 1


//////////////////////
6
6
7
/////////////////////////
--------------------
6
6
7
--------------------
7
Removed 1 stack 3
//////////////////////
6
6
6
/////////////////////////
 * 
 * 
Height=6

 * 
 * 
 * 
 */
