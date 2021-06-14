package RecursionPractice;

import java.util.ArrayList;

public class keyPadCombinations {

	public static void main(String[] args) {
		String str="678";
		ArrayList<String> res=keyPadComb(str);
		System.out.println(res);

	}

	private static ArrayList<String> keyPadComb(String str) {
		String[] code= {".,","abc","def","ghi","kjl","mno","pqrs","tuv","wx","yz"};
		
		if(str.length()==0)
		{
			ArrayList<String> baseCase=new ArrayList<>();
			baseCase.add("");
			return baseCase;
		}
		char firstChar=str.charAt(0); 
		String remChar=str.substring(1);
		String codeChar=code[firstChar];
		ArrayList<String> recRes=keyPadComb(remChar);
		ArrayList<String> result=new ArrayList<>(); 
		
		for(String myStr:recRes)
		{
			for(int i=0;i<codeChar.length();i++)
			{
				result.add(codeChar.charAt(i)+myStr);
			}
		}
		
		return result;
	}

}
