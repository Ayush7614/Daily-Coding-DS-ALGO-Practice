package RandomProblems;

import java.awt.List;
import java.util.HashSet;
import java.util.Set;

public class PrintSubsequence {
	
	static Set<String> res=new HashSet();

	public static void main(String[] args) {
		
		String[] arrStr=new String[10];
		
		String str="abc";
		printSubsequence(str,"");
	}

	private static void printSubsequence(String str,String seq) {
		
		if(str.length()==0)
		{
			res.add(seq);
			return;
		}
		printSubsequence(str.substring(1),seq+str.charAt(0));
		printSubsequence(str.substring(1),seq);
		System.out.print(seq+" ");
	}

}
