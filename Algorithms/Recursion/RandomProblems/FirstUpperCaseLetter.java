package RandomProblems;
import java.util.Scanner;

public class FirstUpperCaseLetter {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		String input=sc.next();
		int index=firstUpperCaseLetter(input,0);
		System.out.println(index);
	}

	private static int firstUpperCaseLetter(String input,int first) {

		if(input.charAt(first)<=65&&input.charAt(first)<=90)
		{
			return first;
		}
		if(Character.isUpperCase(input.charAt(first)))
		{
			return first;
		}
		return firstUpperCaseLetter(input,first+1);
	}
}
