package RecursionPractice;

import java.util.ArrayList;

public class subSequence {

	public static void main(String[] args) {
		String str="abc";
		ArrayList<String> al=printSubsequence(str);
		System.out.println(al);
	}

	private static ArrayList<String> printSubsequence(String str) {
		if(str.length()==0)
		{
			ArrayList<String> baseCase = new ArrayList<>();
			 baseCase.add("");
			return baseCase;
			
		}
		char firstChar=str.charAt(0);
		String restOfTheChar=str.substring(1);
		ArrayList<String> recursionResult=printSubsequence(restOfTheChar);
		ArrayList<String> res=new ArrayList<>();
		for(String myResult:recursionResult)
		{
			res.add(myResult+"");
			res.add(firstChar+myResult);
		}
		return res;
	}

}
