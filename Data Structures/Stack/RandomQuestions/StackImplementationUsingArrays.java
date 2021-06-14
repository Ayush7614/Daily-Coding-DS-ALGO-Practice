package RandomQuestions;

import java.util.Scanner;

public class StackImplementationUsingArrays {
	
	static int[] arr=new int[10];
	static Scanner sc=new Scanner(System.in);
	static int t;
	
	public static void main(String[] args) {
		
		
		for(int i=0;i<10;i++)
		{
			arr[i]=-1;
		}
		
		
		
		
		
		
		
		
		
		while(true) {
		
		System.out.println("Enter your choice(numeric value only");
		System.out.println("1->push");
		System.out.println("2->pop");
		System.out.println("3->size");
		System.out.println("4->display");
		System.out.println("5->Exit");
		int choice=sc.nextInt();
		switch(choice)
		{
		
			case 1:push();
			break;
			
			case 2:pop();
			break;
			
			case 3:size();
			break;
			
			case 4:display();
			break;
			
			case 5: System.exit(0);
			break;
			
			default: System.out.println("Invalid Choice,please try again");
			break;
		
		}
		}

	}

	private static void display() {
		
		System.out.print("Stack contains:");
		
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]==-1)
			{
				continue;
			}
			else
			{
				System.out.print(" "+arr[i]+" ");
			}
		}
		System.out.println();
		
	}

	private static void size() {
		System.out.println("Stack Size="+t);
	}

	private static void pop() {
		t--;
		arr[0]=-1;
		
	}

	private static void push() {
		
		t++;
		
		System.out.println("Enter the value(numeric value only)");
		int value=sc.nextInt();
		
		 
		for(int i=0;i<10;i++)
		{
			if(arr[i]==-1)
			{
				arr[i]=value;
				break;
			}
		}
		
		
	}

}
