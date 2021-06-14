package RandomProblems;

public class ReverseOrder {

	public static void main(String[] args) {
		String str="hello";
		//should return 'olleh'
		String rev=reverseOrder(str,str.length());
		System.out.println(rev);

	}

	private static String reverseOrder(String str,int len) {
		
		if(len==0)
		{
			return "";
		}
		String rev=str.charAt(len-1)+"";
		//following recursive leap of faith approach
		return rev+reverseOrder(str,len-1);
	}

}
