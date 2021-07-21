import java.util.*;
public class StackArray
{
	int top;
	int capacity=10;
	int[] array = new int[capacity];
	
	StackArray()
	{
		top = -1;
	}
	
	public boolean isEmpty()
	{
		return (top<0);
	}
	
	public void push(int value)
	{
		if(top==(capacity-1))
		    System.out.println("Stack Overflow");
		
		else
			top++;
		    array[top]=value;
			System.out.println("Item pushed "+value);
	}
	
	public int pop()
	{
		if(top==-1)
		{
			System.out.println("Stack Underflow");
		    return -1;
		}
		
		else
		{
			int popped_value = array[top];
			top--;
			System.out.println("Item Popped "+popped_value);
			return popped_value;
		}
	}
	
	public void Display()
	{
		System.out.print("Stack Elements ");
		for(int i=top; i>=0; i--)
		{
			System.out.printf("%d ",array[i]);
		}
		
		System.out.println();
	}
	
	public int peek()
	{
	    if(top==-1)
			System.out.println("Stack Underflow");
		
		else
			System.out.println("Top value is "+array[top]);
			return array[top];
	}
	
	public static void main(String[] args)
	{
	    Scanner in = new Scanner(System.in);
		  StackArray obj = new StackArray();
		  obj.push(9);
		  obj.push(18);
		  obj.push(10);
		  obj.pop();
		  obj.Display();
		  obj.peek();
	}
}
