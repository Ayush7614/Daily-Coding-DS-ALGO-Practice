package RandomProblems;

import java.util.Scanner;

public class CountConsonants {

	public static void main(String[] args) {
		
		System.out.println("Enter a string");
		Scanner sc=new Scanner(System.in);
		String input=sc.next();
		int total=countConsonants(input,input.length());
		System.out.println(total);

	}

	private static int countConsonants(String input,int len) 
	{
		if(len==1)
		{
			if(isConsonant(input.charAt(0)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		
		if(isConsonant(input.charAt(len-1)))
		{
			return countConsonants(input,len-1)+1;
			//since there is consonant,we call the method and add 1 to it(like incrementing the count).
		}
		else
		{
			return countConsonants(input,len-1);
			//since its a vowel,just call the method again.
		}
	}

	private static boolean isConsonant(char ch) {
		
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	

}
