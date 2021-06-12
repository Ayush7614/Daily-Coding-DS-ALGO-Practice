import java.util.*;

public class Main
{
	public final static int d = 256;
	
	static void index(String second, String first, int q)
	{
		int sec = second.length();
		int fir = first.length();
		int i, j;
		int p = 0; 
		int t = 0; 
		int h = 1;
	
		for (i=0; i<sec-1; i++)
			h = (h*d)%q;
	
		for (i=0; i<sec; i++)
		{
			p = (d*p + second.charAt(i))%q;
			t = (d*t + first.charAt(i))%q;
		}
		
		for (i=0; i<=fir-sec; i++)
		{
			if (p == t)
			{
				for (j=0; j<sec; j++)
				{
					if (first.charAt(i+j) != second.charAt(j))
						break;
				}
				if (j==sec)
					System.out.println("Pattern found at index "+i);
			}
	
			if (i<fir-sec)
			{
				t = (d*(t-first.charAt(i)*h) + first.charAt(i+sec))%q;
				if (t<0)
				t = (t+q);
			}
		}
	}
	
	public static void main(String[] args)
	{
		String first ;
		String second ;
		Scanner sc = new Scanner(System.in);
		  first = sc.nextLine();
		  second = sc.nextLine();
		int q = 101;

		index(second, first, q);
	}
}
/*
Input :- codechef and code
       :-  code
 Output :- Pattern found at index 0
 Output :- Pattern found at index 13
*/

/*
Time Complexity :- o(n+m)
*/

