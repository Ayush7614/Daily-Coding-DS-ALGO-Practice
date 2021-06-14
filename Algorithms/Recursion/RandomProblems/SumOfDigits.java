package RandomProblems;

public class SumOfDigits {

	public static void main(String[] args) {
		
		String num="1234"; //alter your input here
		// it should return 10[1+2+3+4]
		int sum=sumOfDigits(num,num.length());
		System.out.println(sum);
	}

	private static int sumOfDigits(String num,int len) {
		
		// base case
		
		if(len==0)
		{
			return 0;
		}
		
		String n=num.charAt(len-1)+"";
		int add=Integer.parseInt(n);
		
		// By recursive leap of faith,you calculate for last digit,rest will be taken care by the recursive call.
		return add+sumOfDigits(num,len-1);
	}

}
