package RandomQuestions;

import java.util.Scanner;
import java.util.Stack;

public class InfixConversions {

	public static void main(String[] args) {
		/*
		 * Algorithm:
		 * 
		 *   if you see:
		 *  		operand->push to operandStack
		 *               ( ->push to operatorStack
		 *               ) ->pop operatorStack until (
		 *               * ->pop until you find small priority or )
		 *               / ->pop until you find small priority or )
		 *               + ->pop until you find small priority or )
		 *               - ->pop until you find small priority or )
		 *               
		 *               while you pop:
		 *                  
		 *                  take top two operands from operandsStack and
		 *                  and perform operation with top operator in operatorStack
		 *                  and store in operandStack.
		 */
		
		
		Scanner sc=new Scanner(System.in);		
		String exp=sc.next();
		sc.close();
		
		Stack<Integer> operandStack=new Stack<>();
		Stack<Character> operatorStack=new Stack<>();
		for(int i=0;i<exp.length();i++)
		{
			char ch=exp.charAt(i);
			if(ch=='(')
			{
				
			}
			else if(Character.isDigit(ch))
			{
				operandStack.push(ch-'0');
			}
			else if(ch==')')
			{
				while(operatorStack.size()!=0 && operatorStack.peek()!='('  )
				{
					char operator=operatorStack.pop();
					int v2=operandStack.pop();
					int v1=operandStack.pop();
					
					int opvalue=performOperation(v1,v2,operator);
					operandStack.push(opvalue);
				}
				if(operatorStack.size()>0)
				{
					operatorStack.pop();
				}
			}
			else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
			{
				while(operatorStack.size()>0 && operatorStack.peek()!='(' && 
						precedence(ch)<=precedence(operatorStack.peek()))
				{
					char operator=operatorStack.pop();
					int v2=operandStack.pop();
					int v1=operandStack.pop();
					int opvalue=performOperation(v1,v2,operator);
					operandStack.push(opvalue);
				}
				operatorStack.push(ch);
			}
		}
			
			while(operatorStack.size()!=0)
			{
				char operator=operatorStack.pop();
				int v2=operandStack.pop();
				int v1=operandStack.pop();
				int opvalue=performOperation(v1,v2,operator);
				operandStack.push(opvalue);
			}
			System.out.println(operandStack.peek());
		}

	public static int precedence(char operator) {
		if(operator=='+') 
		{
			return 1;
		}
		else if(operator=='-')
		{
			return 1;
		}
		else if(operator=='*')
		{
			return 2;
		}
		else
		{
			return 2;
		}
	}
	public static int performOperation(int v1,int v2,char operator)
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
