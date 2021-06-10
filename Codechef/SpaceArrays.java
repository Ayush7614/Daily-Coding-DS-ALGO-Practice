import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n  = sc.nextInt();
		    int sum = 0;
		    boolean flag = false;
		    int[] a = new int[n];
		    for(int i = 0 ; i < n ; i++){
		        a[i] = sc.nextInt();
		    
		}
		Arrays.sort(a);
		for(int i = 0 ; i < n ; i++){
		     sum += Math.abs((i+1)-a[i]);
		     if(a[i]>(i+1))
		        flag = true;
		}
		if((sum % 2 == 0)||(flag == true))
		    System.out.println("Second");
		else
		    System.out.println("First");
		}
	}
}
