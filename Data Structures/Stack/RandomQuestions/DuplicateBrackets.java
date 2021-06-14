package RandomQuestions;

import java.util.Scanner;
import java.util.Stack;

public class DuplicateBrackets {

	public static void main(String[] args) throws Exception {
		
		Stack<Character> st=new Stack<Character>();
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a String");
		String str=sc.nextLine();
		int len=str.length();
		sc.close();
		if(len%2!=0)
		{
			System.out.println("False");
			System.exit(0);
		}
		else
		{
		
		for(int i=0;i<str.length();i++) 
		{
			char ch=str.charAt(i);
			if(ch==')') 
			{
				if(!st.isEmpty())
				{
				if(st.peek()=='(') 
				{
					st.pop();
				}
				}
				else
				{
					st.push(ch);
					if(!st.isEmpty())
					{
					try {
					while(st.peek()!='(')
					{
						st.pop();
					}
					}
					catch(Exception e)
					{
						System.out.println("False");
						System.exit(0);
					}
					st.pop();
					}
				}
				
			}
			else
			{
				st.push(ch);
			}
		}
		System.out.println(st.isEmpty());

	}

}
}
