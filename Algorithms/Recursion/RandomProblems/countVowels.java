package RandomProblems;

import java.util.Scanner;

public class countVowels {

	public static void main(String[] args) {
		
		System.out.println("Enter a string");
		Scanner sc=new Scanner(System.in);
		String input=sc.next();
		int total=countVowels(input,input.length());
		System.out.println(total);

	}

	private static int countVowels(String input,int len) 
	{
		if(len==1)
		{
			if(isVowel(input.charAt(0)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		
		if(isVowel(input.charAt(len-1)))
		{
			return countVowels(input,len-1)+1;
			//since there is vowel,we call the method and add 1 to it.
		}
		else
		{
			return countVowels(input,len-1);
			//since its not a vowel,just call the method again.
		}
	}

	private static boolean isVowel(char ch) {
		
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

}
