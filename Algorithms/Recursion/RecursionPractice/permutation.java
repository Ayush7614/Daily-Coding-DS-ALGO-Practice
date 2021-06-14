package RecursionPractice;

import java.util.Scanner;

public class permutation {

	public static void main(String[] args) {
	
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter string");
		String str=sc.next();
		printPermutations(str,"");

	}

	private static void printPermutations(String str, String asf) {
	
		if(str.length()==0)
		{
			System.out.println(asf);
			return;
		}
		for(int i=0;i<str.length();i++)
		{
			char ch=str.charAt(i);
			String left=str.substring(0,i);
			String right=str.substring(i+1);
			String total=left+right;
			printPermutations(total,asf+ch);
		}
		
	}

}
