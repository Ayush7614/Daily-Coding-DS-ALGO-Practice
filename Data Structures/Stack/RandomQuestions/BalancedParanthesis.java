package RandomQuestions;

import java.util.Scanner;
import java.util.Stack;
public class BalancedParanthesis {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a String");
		String str=sc.next();
		sc.close();
		boolean bool=isBalanced(str);
		System.out.println(bool);

	}

	private static boolean isBalanced(String str) {
		
		Stack<Character> st=new Stack<>();
		for(int i=0;i<str.length();i++)
		{
			try
			{
			char ch=str.charAt(i);
			if(ch=='('||ch=='{'||ch=='[')
			{
				st.push(ch);
			}
			else if(ch==')')
			{
				while(st.peek()!='(')
				{
					st.pop();
				}
				st.pop();
			}
			else if(ch=='}')
			{
				while(st.peek()!='{')
				{
					st.pop();
				}
				st.pop();
			}
			else if(ch==']')
			{
				while(st.peek()!='[')
				{
					st.pop();
				}
				st.pop();
			}
			}
			catch(Exception e)
			{
				return false;
			}
		}
		boolean bool=st.isEmpty();
		return bool;
		
	}

}
