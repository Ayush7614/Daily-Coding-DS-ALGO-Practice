/*Link to the problem-
https://www.codechef.com/START5C/problems/CHEFQUER/
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class queries
{
	public static void main (String[] args) throws java.lang.Exception
	{

		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int q=sc.nextInt();
		long arr[]=new long[n+1];
		for(int i=1;i<=n;i++){
		    arr[i]=sc.nextLong();
		}
		
		while(q-->0){
		    int t = sc.nextInt();
		    if(t==1){
		        int l=sc.nextInt();
		        int r=sc.nextInt();
		        int x=sc.nextInt();
		        for(int i=l;i<=r;i++){
		            long val = (x+i-l);
		            val*=(x+i-l);
		            arr[i]+=val;
		        }
		    }else if(t==2){
		        int y=sc.nextInt();
		        System.out.println(arr[y]);
		    }
	}
}
}

/*
Input-
5 4
1 10 3 6 5
1 1 3 5
2 3
1 4 5 7
2 5

Output-
52
69
*/
