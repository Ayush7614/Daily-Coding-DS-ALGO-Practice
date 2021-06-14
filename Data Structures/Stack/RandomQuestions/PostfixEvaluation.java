package RandomQuestions;

import java.util.Scanner;
import java.util.Stack;

public class PostfixEvaluation {

	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String exp=sc.next();
		sc.close();
		Stack<Integer> valueStack=new Stack<>();
		Stack<String> infixStack=new Stack<>();
		Stack<String> preStack=new Stack<>();
		
		
		for(int i=0;i<exp.length();i++)
		{
			char ch=exp.charAt(i);
			
			if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
			{
				int v1=valueStack.pop();
				int v2=valueStack.pop();
				int val=performOperation(v1,v2,ch);
				valueStack.push(val);
				
				String if2=infixStack.pop();
				String if1=infixStack.pop();
				String infixValue="("+if1+ch+if2+")";
				infixStack.push(infixValue);
				
				
				String pv2=preStack.pop();
				String pv1=preStack.pop();
				String prefixValue=ch+pv1+pv2;
				preStack.push(prefixValue);
			}
			else
			{
				valueStack.push(ch-'0');
				infixStack.push(ch+"");
				preStack.push(ch+"");
				
			}
		}
		try {
			
			System.out.println("Value:"+valueStack.pop());
        }
		catch(Exception EmptyStackException)
		{
			System.out.println("Empty valueStack");
		}
		try
		{
			System.out.println("Infix expression:"+infixStack.pop());
		}
		catch(Exception EmptyStackException)
		{
			System.out.println("Empty infixStack");
		}
		try
		{
			System.out.println("Prefix Expression:"+preStack.pop());
		}
		catch(Exception EmptyStackException)
		{
			System.out.println("Empty preStack");
		}
		

	}

	private static int performOperation(int v1, int v2, char operator) 
	{
		
		if(operator=='+')
		{
			return v1+v2;
		}
		else if(operator=='-')
		{
			return v1-v2;
		}
		else if(operator=='*')
		{
			return v1*v2;
		}
		else
		{
			return v1/v2;
		}
	}

}